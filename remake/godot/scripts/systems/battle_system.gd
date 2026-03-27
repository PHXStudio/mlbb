extends Node

# 信号定义
signal battle_started(battle_id: int, init_battle: COM_InitBattle)
signal battle_ended(battle_type: int, result: COM_BattleOverClearing)
signal battle_enter_requested(scene_path: String)
signal battle_exit_requested(scene_path: String)
signal round_started(round: int, current_uid: int)
signal round_action_received(report: COM_BattleReport)
signal actions_queued(actions: Array[Dictionary])
signal action_playback_started(action: Dictionary)
signal action_playback_finished(action: Dictionary)
signal entity_updated(position: int, entity)
signal battle_status_changed(in_battle: bool)

# 战斗状态枚举
enum BattleState {
	IDLE,
	ENTERING,
	FIGHTING,
	ROUND_WAITING,
	ENDING,
	ENDED
}

# 核心数据
var _current_state: BattleState = BattleState.IDLE
var _battle_id: int = 0
var _battle_type: int = 0
var _round_count: int = 0
var _current_round: int = 1
var _entities: Dictionary = {}  # position -> BattleEntity
var _current_actor_uid: int = 0
var _in_battle: bool = false
var _pending_actions: Array[Dictionary] = []
var _parser: BattleReportParser = BattleReportParser.new()

# 初始化战斗
func init_battle(init_battle: COM_InitBattle) -> void:
	if init_battle == null:
		return
	if _current_state == BattleState.FIGHTING and _battle_id == init_battle.battleId_ and not _entities.is_empty():
		print("BattleSystem.init_battle: ignore duplicated enter packet, battle_id=", _battle_id)
		return

	_current_state = BattleState.ENTERING
	_battle_id = init_battle.battleId_
	_battle_type = init_battle.bt_
	_round_count = init_battle.roundCount_
	_current_round = 1
	_current_actor_uid = 0
	_entities.clear()
	_pending_actions.clear()

	print("BattleSystem.init_battle: battle_id=", _battle_id, ", type=", _battle_type)

	# 解析战斗实体
	if init_battle.actors_ != null:
		for entity_info in init_battle.actors_:
			if entity_info != null:
				var pos = entity_info.battlePosition_
				_entities[pos] = BattleEntity.create(entity_info, is_my_team(pos))
				print("  实体 pos=", pos, ", name=", entity_info.instName_, ", hp=", entity_info.hpCrt_, "/", entity_info.hpMax_)

	_current_state = BattleState.FIGHTING
	_in_battle = true
	battle_status_changed.emit(true)
	battle_started.emit(_battle_id, init_battle)
	battle_enter_requested.emit("res://assets/ui/battle/battle_panel.tscn")

# 处理回合战报
func process_turn_report(report: COM_BattleReport) -> void:
	if report == null:
		return
	if _current_state != BattleState.FIGHTING:
		print("BattleSystem.process_turn_report: ignore report in state=", _current_state)
		return

	print("BattleSystem.process_turn_report: round=", _current_round)
	var parsed_actions = _parser.parse_report(report, _current_round)
	if parsed_actions.is_empty():
		round_action_received.emit(report)
		return

	for action in parsed_actions:
		_apply_action(action)
		_pending_actions.append(action)

	actions_queued.emit(parsed_actions)
	round_action_received.emit(report)
	_pending_actions.clear()

# 结束战斗
func end_battle(battle_type: int, clearing: COM_BattleOverClearing) -> void:
	print("BattleSystem.end_battle: type=", battle_type)
	if _current_state == BattleState.IDLE or _current_state == BattleState.ENDED:
		return
	_current_state = BattleState.ENDING
	_in_battle = false
	_pending_actions.clear()
	battle_ended.emit(battle_type, clearing)
	battle_status_changed.emit(false)
	battle_exit_requested.emit("res://assets/ui/main_game.tscn")
	_current_state = BattleState.ENDED

# 设置当前行动单位
func set_current_actor(uid: int) -> void:
	if _current_state != BattleState.FIGHTING:
		print("BattleSystem.set_current_actor: ignore in state=", _current_state)
		return
	_current_actor_uid = uid
	print("BattleSystem.set_current_actor: uid=", uid)

# 下一回合
func next_round() -> void:
	if _current_state != BattleState.FIGHTING:
		print("BattleSystem.next_round: ignore in state=", _current_state)
		return
	_current_round += 1
	print("BattleSystem.next_round: round=", _current_round)
	round_started.emit(_current_round, _current_actor_uid)

# 获取实体
func get_entity(position: int):
	return _entities.get(position, null)

# 获取所有实体
func get_all_entities() -> Dictionary:
	return _entities

# 判断是否我方 (position 0-2 为我方)
func is_my_team(position: int) -> bool:
	return position >= 0 and position <= 2

# 判断是否敌方 (position 3-5 为敌方)
func is_enemy_team(position: int) -> bool:
	return position >= 3 and position <= 5

# 获取当前状态
func get_state() -> BattleState:
	return _current_state

# 获取战斗ID
func get_battle_id() -> int:
	return _battle_id

# 获取战斗类型
func get_battle_type() -> int:
	return _battle_type

# 获取当前回合
func get_current_round() -> int:
	return _current_round

# 获取总回合数
func get_round_count() -> int:
	return _round_count

# 是否在战斗中
func is_in_battle() -> bool:
	return _in_battle

# 设置战斗状态
func set_battle_status(in_battle: bool) -> void:
	_in_battle = in_battle
	if in_battle and _current_state == BattleState.IDLE:
		_current_state = BattleState.ENTERING
	elif not in_battle and _current_state != BattleState.IDLE:
		_current_state = BattleState.IDLE
	battle_status_changed.emit(in_battle)

func mark_action_playback_started(action: Dictionary) -> void:
	action_playback_started.emit(action)

func mark_action_playback_finished(action: Dictionary) -> void:
	action_playback_finished.emit(action)

func _apply_action(action: Dictionary) -> void:
	var action_type = action.get("action_type", "")
	if action_type == BattleReportParser.ACTION_WAVE_ENTITY:
		var entity_info = action.get("entity_info", null)
		if entity_info != null:
			var pos = entity_info.battlePosition_
			_entities[pos] = BattleEntity.create(entity_info, is_my_team(pos))
			entity_updated.emit(pos, _entities[pos])
		return

	var pos = action.get("target_position", -1)
	if pos < 0:
		return

	var entity = get_entity(pos)
	if entity == null:
		return

	var hp_delta = int(action.get("hp_delta", 0))
	if hp_delta < 0:
		entity.take_damage(-hp_delta)
	elif hp_delta > 0:
		entity.heal(hp_delta)
	entity_updated.emit(pos, entity)
