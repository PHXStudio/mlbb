extends Control

@onready var player_list = $PlayerListContainer/PlayerList
@onready var enter_button = $ButtonPanel/EnterButton
@onready var create_button = $ButtonPanel/CreateButton
@onready var delete_button = $ButtonPanel/DeleteButton
@onready var status_label = $StatusLabel

var _selected_player: COM_SimpleInformation = null
var _player_cards: Array = []

func _ready() -> void:
	# 获取角色列表
	var players = PlayerSystem.get_players()
	_refresh_player_list(players)

	enter_button.pressed.connect(_on_enter_pressed)
	create_button.pressed.connect(_on_create_pressed)
	delete_button.pressed.connect(_on_delete_pressed)

func _refresh_player_list(players: Array) -> void:
	# 清空现有列表
	for card in _player_cards:
		card.queue_free()
	_player_cards.clear()

	# 创建角色卡片
	for player in players:
		var card = _create_player_card(player)
		player_list.add_child(card)
		_player_cards.append(card)

		# 使用闭包连接点击事件
		card.pressed.connect(_on_player_card_clicked.bind(player))

func _create_player_card(player: COM_SimpleInformation) -> Button:
	var button = Button.new()
	button.text = "%s (Lv.%d)" % [player.instName_, player.level_]
	button.custom_minimum_size = Vector2(400, 60)
	return button

func _on_player_card_clicked(player: COM_SimpleInformation) -> void:
	_selected_player = player
	status_label.text = "已选择: " + player.instName_

	# 高亮选中的卡片
	for i in range(_player_cards.size()):
		var card = _player_cards[i]
		if PlayerSystem.get_players()[i] == player:
			card.modulate = Color(1.2, 1.2, 1.0)
		else:
			card.modulate = Color(1.0, 1.0, 1.0)

func _on_enter_pressed() -> void:
	if _selected_player == null:
		status_label.text = "请先选择角色"
		return

	status_label.text = "正在进入游戏..."
	enter_button.disabled = true

	# 发送进入游戏请求
	if Global.get_server_stub() != null:
		Global.get_server_stub().enterGame(_selected_player.instId_)

func _on_create_pressed() -> void:
	# 跳转到创建角色界面（3D 版本）
	Global.change_scene("res://assets/ui/create_player_3d.tscn")

func _on_delete_pressed() -> void:
	if _selected_player == null:
		status_label.text = "请先选择角色"
		return

	# 删除角色
	if Global.get_server_stub() != null:
		Global.get_server_stub().deletePlayer(_selected_player.instName_)

# 供 server2client_handler 调用
func refresh_after_delete() -> void:
	var players = PlayerSystem.get_players()
	_selected_player = null
	_refresh_player_list(players)
	status_label.text = "角色已删除"
