extends Control

@onready var username_input = $LoginPanel/UsernameInput
@onready var password_input = $LoginPanel/PasswordInput
@onready var login_button = $LoginPanel/LoginButton
@onready var status_label = $StatusLabel

var server_agent: ServerAgent

func _ready() -> void:
	server_agent = Global.server_agent
	login_button.pressed.connect(_on_login_pressed)
	status_label.text = ""
	# 连接回车键登录
	username_input.text_submitted.connect(_on_username_submitted)
	password_input.text_submitted.connect(_on_password_submitted)

func _on_username_submitted(text: String) -> void:
	password_input.grab_focus()

func _on_password_submitted(text: String) -> void:
	_on_login_pressed()

func _on_login_pressed() -> void:
	var username = username_input.text.strip_edges()
	var password = password_input.text.strip_edges()

	if username.is_empty():
		status_label.text = "请输入用户名"
		return

	if password.is_empty():
		status_label.text = "请输入密码"
		return

	status_label.text = "正在连接服务器..."
	login_button.disabled = true

	# 发送登录请求
	if server_agent != null and server_agent.get_server_stub() != null:
		var info =  COM_LoginInfo.new()
		info.username_ = username
		info.password_ = password
		server_agent.get_server_stub().login(info)
	else:
		status_label.text = "服务器连接失败"
		login_button.disabled = false

# 供 server2client_handler 调用的回调函数
func on_login_success() -> void:
	status_label.text = "登录成功！"

func on_login_failed(error_code: int) -> void:
	status_label.text = "登录失败: 错误码 " + str(error_code)
	login_button.disabled = false
