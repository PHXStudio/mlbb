extends Node2D


@onready var connection: Connection = $Connection


func _on_ready() -> void:
	connection.connect_to_host("0.0.0.0",21000)
	
	var logininfo : COM_LoginInfo = COM_LoginInfo.new()
	logininfo.username_ = "godotnew"
	logininfo.password_ = "haha"
	
	connection.login(logininfo)
	
	pass # Replace with function body.
	
