extends Control

@onready var name_label = $TopBar/PlayerInfo/NameLabel
@onready var level_label = $TopBar/PlayerInfo/LevelLabel
@onready var exp_bar = $TopBar/PlayerInfo/ExpBar
@onready var hp_label = $TopBar/PlayerInfo/HPLabel
@onready var mp_label = $TopBar/PlayerInfo/MPLabel
@onready var bag_button = $BottomBar/BagButton
@onready var baby_button = $BottomBar/BabyButton
@onready var employee_button = $BottomBar/EmployeeButton
@onready var battle_button = $BottomBar/BattleButton
@onready var menu_button = $TopBar/MenuButton

func _ready() -> void:
	_refresh_player_info()

	bag_button.pressed.connect(_on_bag_pressed)
	baby_button.pressed.connect(_on_baby_pressed)
	employee_button.pressed.connect(_on_employee_pressed)
	battle_button.pressed.connect(_on_battle_pressed)
	menu_button.pressed.connect(_on_menu_pressed)

func _refresh_player_info() -> void:
	var player = PlayerSystem.get_current()
	if player == null:
		name_label.text = "未登录"
		level_label.text = ""
		return

	name_label.text = player.instName_
	level_label.text = "Lv." + str(PlayerSystem.get_level())

	# 更新HP/MP
	var hp = PlayerSystem.get_hp()
	var hp_max = PlayerSystem.get_hp_max()
	hp_label.text = "HP: %d/%d" % [hp, hp_max]

	var mp = PlayerSystem.get_mp()
	var mp_max = PlayerSystem.get_mp_max()
	mp_label.text = "MP: %d/%d" % [mp, mp_max]

func _on_bag_pressed() -> void:
	print("打开背包")

func _on_baby_pressed() -> void:
	print("打开宝宝")

func _on_employee_pressed() -> void:
	print("打开员工")

func _on_battle_pressed() -> void:
	var stub = Global.get_server_stub()
	if stub == null:
		print("server stub 为空，直接进入本地战斗场景")
		Global.change_scene("res://assets/ui/battle/battle_panel.tscn")
		return
	# 按需求固定进入 battleId=1
	stub.enterBattle(1)
	print("请求进入战斗: battleId=1")
	# 本地兜底：即使回包延迟也先展示战斗场景
	if not BattleSystem.is_in_battle():
		Global.change_scene("res://assets/ui/battle/battle_panel.tscn")

func _on_menu_pressed() -> void:
	# 显示菜单（退出、设置等）
	print("打开菜单")
