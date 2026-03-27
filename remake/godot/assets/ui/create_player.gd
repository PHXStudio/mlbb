extends Control

@onready var name_input = $FormPanel/NameInput
@onready var confirm_button = $FormPanel/ConfirmButton
@onready var back_button = $BackButton
@onready var status_label = $StatusLabel
@onready var class_container = $FormPanel/ClassContainer

var _selected_template: int = 1  # 默认模板ID
var _template_buttons: Array = []

func _ready() -> void:
	confirm_button.pressed.connect(_on_confirm_pressed)
	back_button.pressed.connect(_on_back_pressed)
	name_input.text_submitted.connect(_on_name_submitted)

	# 创建种族模板选择按钮
	_create_template_buttons()

func _create_template_buttons() -> void:
	var templates = PlayerTemplateData.get_all_templates()

	for template_info in templates:
		var button = Button.new()
		button.text = template_info.race  # 显示种族名称
		button.custom_minimum_size = Vector2(150, 60)
		button.pressed.connect(_on_template_selected.bind(template_info.id, button))
		class_container.add_child(button)
		_template_buttons.append(button)

		# 默认选中第一个模板
		if template_info.id == templates[0].id:
			_on_template_selected(template_info.id, button)

func _on_template_selected(template_id: int, button: Button) -> void:
	_selected_template = template_id
	var template_info = PlayerTemplateData.get_template_by_id(template_id)
	if template_info != null:
		status_label.text = "已选择种族: " + template_info.race
		if not template_info.race_desc.is_empty():
			status_label.text += "\n" + template_info.race_desc

	# 更新按钮样式
	for btn in _template_buttons:
		btn.modulate = Color(1.0, 1.0, 1.0)
	button.modulate = Color(1.2, 1.2, 1.0)

func _on_name_submitted(text: String) -> void:
	_on_confirm_pressed()

func _on_confirm_pressed() -> void:
	var name = name_input.text.strip_edges()

	if name.is_empty():
		status_label.text = "请输入角色名"
		return

	if name.length() < 2 or name.length() > 12:
		status_label.text = "角色名长度为2-12个字符"
		return

	confirm_button.disabled = true
	status_label.text = "正在创建角色..."

	# 发送创建请求：使用模板ID而非职业ID
	if Global.get_server_stub() != null:
		Global.get_server_stub().createPlayer(name, _selected_template)

func _on_back_pressed() -> void:
	# 返回角色选择界面
	var players = PlayerSystem.get_players()
	if players.is_empty():
		Global.change_scene("res://assets/ui/login_panel.tscn")
	else:
		Global.change_scene("res://assets/ui/player_select.tscn")

# 供 server2client_handler 调用
func on_create_success() -> void:
	status_label.text = "角色创建成功！正在进入游戏..."
