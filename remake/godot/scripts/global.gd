extends Node

var server_agent: ServerAgent = ServerAgent.new()
var server_handler: Server2ClientHandler

func _ready() -> void:
	_connect_battle_signals()
	init_network()

func _process(delta: float) -> void:
	server_agent.tick_frame()

func init_network():
	server_handler = Server2ClientHandler.new()
	server_handler.set_proxy(server_agent.get_server_proxy(), server_agent)
	server_agent.get_net_conn().connect_to_host("127.0.0.1", 21000)

# 场景切换辅助方法（供 Server2ClientHandler 调用）
func change_scene(scene_path: String) -> void:
	get_tree().change_scene_to_file(scene_path)

# 获取服务器存根（供 UI 调用）
func get_server_stub() -> ServerStub:
	return server_agent.get_server_stub()

func _connect_battle_signals() -> void:
	if BattleSystem.has_signal("battle_enter_requested") and not BattleSystem.battle_enter_requested.is_connected(_on_battle_enter_requested):
		BattleSystem.battle_enter_requested.connect(_on_battle_enter_requested)
	if BattleSystem.has_signal("battle_exit_requested") and not BattleSystem.battle_exit_requested.is_connected(_on_battle_exit_requested):
		BattleSystem.battle_exit_requested.connect(_on_battle_exit_requested)

func _on_battle_enter_requested(scene_path: String) -> void:
	change_scene(scene_path)

func _on_battle_exit_requested(scene_path: String) -> void:
	change_scene(scene_path)
