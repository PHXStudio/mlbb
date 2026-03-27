extends Control

@onready var viewport_container = $ViewportContainer
@onready var name_input = $FormPanel/NameInput
@onready var confirm_button = $FormPanel/ConfirmButton
@onready var back_button = $BackButton
@onready var status_label = $StatusLabel
@onready var left_button = $LeftButton
@onready var right_button = $RightButton

var _selected_index: int = 0
var _templates: Array[PlayerTemplateData.PlayerTemplateInfo] = []
var _character_nodes: Array[Node3D] = []

# 转盘配置
const POSITION_SPACING = 5.0  # 角色之间的间距
const DEPTH_SPACING = 2.0  # 深度方向间距

# 动画相关
var _is_animating: bool = false

func _ready() -> void:
	print("=== create_player_3d _ready() ===")
	print("Children count: ", get_child_count())
	for i in range(get_child_count()):
		print("  Child ", i, ": ", get_child(i).name)
	print("viewport_container: ", viewport_container)
	print("left_button: ", left_button)
	print("right_button: ", right_button)
	print("name_input: ", name_input)
	print("confirm_button: ", confirm_button)
	print("back_button: ", back_button)
	print("status_label: ", status_label)

	if viewport_container == null:
		push_error("viewport_container is null!")
		return

	_templates = PlayerTemplateData.get_all_templates()
	_setup_carousel()
	_connect_signals()
	_update_display()

func _setup_carousel() -> void:
	var viewport = viewport_container.get_node("Viewport")
	var world_root = viewport.get_node("Viewport#WorldRoot")
	var carousel = viewport.get_node("WorldRoot#CharacterCarousel")

	# 创建角色节点
	for i in range(_templates.size()):
		var character_node = Node3D.new()
		character_node.name = "Character" + str(i)

		# 创建 Area3D 用于鼠标交互
		var area = Area3D.new()
		area.name = "InteractionArea"

		# 创建碰撞形状
		var collision = CollisionShape3D.new()
		var shape = BoxShape3D.new()
		shape.size = Vector3(2, 3, 2)
		collision.shape = shape
		area.add_child(collision)

		# 创建 BoxMesh 作为占位符
		var mesh_instance = MeshInstance3D.new()
		mesh_instance.name = "MeshInstance3D"
		var box_mesh = BoxMesh.new()
		box_mesh.size = Vector3(2, 3, 2)
		mesh_instance.mesh = box_mesh
		character_node.add_child(mesh_instance)

		character_node.add_child(area)
		carousel.add_child(character_node)
		_character_nodes.append(character_node)

func _connect_signals() -> void:
	confirm_button.pressed.connect(_on_confirm_pressed)
	back_button.pressed.connect(_on_back_pressed)
	name_input.text_submitted.connect(_on_name_submitted)
	left_button.pressed.connect(_on_left_pressed)
	right_button.pressed.connect(_on_right_pressed)

	# 为每个角色节点的 Area3D 添加输入事件
	for i in range(_character_nodes.size()):
		var character = _character_nodes[i]
		var area = character.get_node("InteractionArea")
		area.input_event.connect(_on_character_input_event.bind(i))

func _update_display() -> void:
	for i in range(_character_nodes.size()):
		var offset = i - _selected_index
		var character = _character_nodes[i]

		# 计算位置和缩放
		var target_position = Vector3()
		var target_scale = Vector3(1, 1, 1)

		if offset == 0:
			target_position = Vector3(0, 0, 0)
			target_scale = Vector3(1.2, 1.2, 1.2)
		elif offset == -1 or offset == 1:
			target_position = Vector3(offset * POSITION_SPACING, 0, DEPTH_SPACING)
			target_scale = Vector3(0.8, 0.8, 0.8)
		elif abs(offset) >= 2:
			target_position = Vector3(offset * POSITION_SPACING, 0, DEPTH_SPACING * 2)
			target_scale = Vector3(0.5, 0.5, 0.5)
		else:
			target_position = Vector3(offset * POSITION_SPACING * 2, 0, DEPTH_SPACING * 3)
			target_scale = Vector3(0.01, 0.01, 0.01)

		# 直接设置位置和缩放（无动画）
		character.position = target_position
		character.scale = target_scale

		# 更新颜色
		var mesh = character.get_node_or_null("MeshInstance3D")
		if mesh != null:
			var material = mesh.get_active_material(0)
			if material == null:
				material = StandardMaterial3D.new()
				mesh.set_surface_override_material(0, material)
			if offset == 0:
				material.albedo_color = Color(1.2, 1.0, 0.6)  # 选中：金色
			else:
				material.albedo_color = Color(0.7, 0.7, 0.7)  # 未选中：灰色

	# 更新 UI
	var current_template = _templates[_selected_index]
	status_label.text = "已选择: %s\n%s" % [current_template.race, current_template.race_desc]

func _on_left_pressed() -> void:
	if _is_animating:
		return

	_selected_index = (_selected_index - 1) % _templates.size()
	_animate_selection()

func _on_right_pressed() -> void:
	if _is_animating:
		return

	_selected_index = (_selected_index + 1) % _templates.size()
	_animate_selection()

func _animate_selection() -> void:
	_is_animating = true

	# 创建一个 tween 并设置为并行模式
	var tween = create_tween()
	tween.set_parallel(true)
	tween.set_ease(Tween.EASE_OUT)
	tween.set_trans(Tween.TRANS_QUART)

	# 为每个角色添加动画
	for i in range(_character_nodes.size()):
		var offset = i - _selected_index
		var character = _character_nodes[i]

		var target_position = Vector3()
		var target_scale = Vector3(1, 1, 1)

		if offset == 0:
			target_position = Vector3(0, 0, 0)
			target_scale = Vector3(1.2, 1.2, 1.2)
		elif offset == -1 or offset == 1:
			target_position = Vector3(offset * POSITION_SPACING, 0, DEPTH_SPACING)
			target_scale = Vector3(0.8, 0.8, 0.8)
		elif abs(offset) >= 2:
			target_position = Vector3(offset * POSITION_SPACING, 0, DEPTH_SPACING * 2)
			target_scale = Vector3(0.5, 0.5, 0.5)
		else:
			target_position = Vector3(offset * POSITION_SPACING * 2, 0, DEPTH_SPACING * 3)
			target_scale = Vector3(0.01, 0.01, 0.01)

		tween.tween_property(character, "position", target_position, 0.3)
		tween.tween_property(character, "scale", target_scale, 0.3)

	# 更新颜色和 UI
	for i in range(_character_nodes.size()):
		var offset = i - _selected_index
		var character = _character_nodes[i]
		var mesh = character.get_node_or_null("MeshInstance3D")
		if mesh != null:
			var material = mesh.get_active_material(0)
			if material == null:
				material = StandardMaterial3D.new()
				mesh.set_surface_override_material(0, material)
			if offset == 0:
				material.albedo_color = Color(1.2, 1.0, 0.6)  # 选中：金色
			else:
				material.albedo_color = Color(0.7, 0.7, 0.7)  # 未选中：灰色

	var current_template = _templates[_selected_index]
	status_label.text = "已选择: %s\n%s" % [current_template.race, current_template.race_desc]

	# 等待动画完成
	await tween.finished
	_is_animating = false

func _on_character_input_event(index: int, camera: Node, event: InputEvent, event_position: Vector3, normal: Vector3, collider: Node) -> void:
	if event is InputEventMouseButton and event.pressed and event.button_index == MOUSE_BUTTON_LEFT:
		# 点击角色，切换到该角色
		if index != _selected_index:
			_selected_index = index
			_animate_selection()

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

	if Global.get_server_stub() != null:
		Global.get_server_stub().createPlayer(name, _templates[_selected_index].id)

func _on_back_pressed() -> void:
	var players = PlayerSystem.get_players()
	if players.is_empty():
		Global.change_scene("res://assets/ui/login_panel.tscn")
	else:
		Global.change_scene("res://assets/ui/player_select.tscn")

func on_create_success() -> void:
	status_label.text = "角色创建成功！正在进入游戏..."

# 支持键盘左右键切换
func _input(event: InputEvent) -> void:
	if event.is_action_pressed("ui_left"):
		_on_left_pressed()
	elif event.is_action_pressed("ui_right"):
		_on_right_pressed()
