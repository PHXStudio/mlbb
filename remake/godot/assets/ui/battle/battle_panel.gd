extends Control

@onready var enemy_container = $BattleSceneArea/EnemyTeam
@onready var my_team_container = $BattleSceneArea/MyTeam
@onready var round_label = $RoundInfo
@onready var action_log = $ActionLog/LogText
@onready var result_panel = $BattleResultPanel
@onready var result_title = $BattleResultPanel/ResultTitle
@onready var exp_label = $BattleResultPanel/ExpLabel
@onready var money_label = $BattleResultPanel/MoneyLabel
@onready var confirm_button = $BattleResultPanel/ConfirmButton

var _entity_ui_map: Dictionary = {}  # position -> BattleEntityUI
var _playback_queue: Array[Dictionary] = []
var _is_playing: bool = false

func _ready() -> void:
	# 连接 BattleSystem 信号
	if BattleSystem.has_signal("battle_started"):
		BattleSystem.battle_started.connect(_on_battle_started)
	if BattleSystem.has_signal("round_action_received"):
		BattleSystem.round_action_received.connect(_on_action_received)
	if BattleSystem.has_signal("actions_queued"):
		BattleSystem.actions_queued.connect(_on_actions_queued)
	if BattleSystem.has_signal("battle_ended"):
		BattleSystem.battle_ended.connect(_on_battle_ended)
	if BattleSystem.has_signal("entity_updated"):
		BattleSystem.entity_updated.connect(_on_entity_updated)
	if BattleSystem.has_signal("round_started"):
		BattleSystem.round_started.connect(_on_round_started)

	result_panel.hide()
	confirm_button.pressed.connect(_on_confirm_clicked)

func _on_battle_started(battle_id: int, init_battle: COM_InitBattle) -> void:
	print("BattlePanel._on_battle_started")
	round_label.text = "回合: 1/" + str(init_battle.roundCount_)
	action_log.text = "战斗开始！\n"

	# 清空之前的实体UI
	for child in enemy_container.get_children():
		child.queue_free()
	for child in my_team_container.get_children():
		child.queue_free()
	_entity_ui_map.clear()

	# 创建实体UI
	var entities = BattleSystem.get_all_entities()
	for pos in entities.keys():
		_create_entity_ui(entities[pos], pos)

func _create_entity_ui(entity, position: int) -> void:
	var entity_ui_scene = load("res://assets/ui/battle/battle_entity_ui.tscn")
	if entity_ui_scene == null:
		print("错误: 无法加载 battle_entity_ui.tscn")
		return

	var entity_ui = entity_ui_scene.instantiate()
	var pos = position

	if BattleSystem.is_my_team(pos):
		my_team_container.add_child(entity_ui)
	else:
		enemy_container.add_child(entity_ui)

	entity_ui.setup(entity)
	_entity_ui_map[pos] = entity_ui

func _on_entity_updated(position: int, entity) -> void:
	if not _entity_ui_map.has(position):
		_create_entity_ui(entity, position)
	if _entity_ui_map.has(position):
		_entity_ui_map[position].update_from_entity(entity)

func _on_round_started(round: int, current_uid: int) -> void:
	round_label.text = "回合: " + str(round) + "/" + str(BattleSystem.get_round_count())

func _on_action_received(report: COM_BattleReport) -> void:
	print("BattlePanel._on_action_received")
	_add_log_entry("--- 回合同步 ---")

func _on_actions_queued(actions: Array[Dictionary]) -> void:
	for action in actions:
		_playback_queue.append(action)
	if not _is_playing:
		_play_next_action()

func _play_next_action() -> void:
	if _playback_queue.is_empty():
		_is_playing = false
		return

	_is_playing = true
	var action = _playback_queue.pop_front()
	BattleSystem.mark_action_playback_started(action)
	_play_action(action)

func _play_action(action: Dictionary) -> void:
	var action_type = action.get("action_type", "")
	var position = int(action.get("target_position", -1))
	var hp_delta = int(action.get("hp_delta", 0))
	var is_critical = bool(action.get("is_critical", false))

	if action_type == BattleReportParser.ACTION_STATE_CHANGE:
		_add_log_entry("状态变化: stateId=" + str(action.get("state_id", 0)))
	elif action_type == BattleReportParser.ACTION_WAVE_ENTITY:
		_add_log_entry("新实体加入战场")
	else:
		if _entity_ui_map.has(position):
			var entity_ui = _entity_ui_map[position]
			if hp_delta < 0:
				entity_ui.show_damage(-hp_delta, is_critical)
				_add_log_entry("目标 " + str(position) + " 受到 " + str(-hp_delta) + " 点伤害")
			elif hp_delta > 0:
				entity_ui.show_heal(hp_delta)
				_add_log_entry("目标 " + str(position) + " 恢复 " + str(hp_delta) + " 点生命")

			var entity = BattleSystem.get_entity(position)
			if entity != null and not entity.is_alive():
				entity_ui.show_death()
				_add_log_entry("目标 " + str(position) + " 已死亡")

	await get_tree().create_timer(0.18).timeout
	BattleSystem.mark_action_playback_finished(action)
	_play_next_action()

func _on_battle_ended(battle_type: int, result: COM_BattleOverClearing) -> void:
	print("BattlePanel._on_battle_ended: type=", battle_type)

	if result == null:
		return

	# 设置结算界面
	if result.isFly_:
		result_title.text = "战斗逃跑"
	else:
		if battle_type == 1:  # 假设1为胜利
			result_title.text = "战斗胜利"
		else:
			result_title.text = "战斗失败"

	exp_label.text = "经验: +" + str(result.playExp_)
	money_label.text = "金币: +" + str(result.money_)

	result_panel.show()

func _on_confirm_clicked() -> void:
	print("BattlePanel._on_confirm_clicked")
	Global.change_scene("res://assets/ui/main_game.tscn")

func _add_log_entry(text: String) -> void:
	action_log.text += text + "\n"
