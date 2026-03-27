extends Button


func _on_ready() -> void:
	
	
	pass # Replace with function body.
	



func _on_pressed() -> void:
	var logininfo : COM_LoginInfo = COM_LoginInfo.new()
	logininfo.username_ = "aas"
	logininfo.password_ = "haha"
	
	Global.server_agent.get_server_stub().login(logininfo)
	
	pass # Replace with function body.
