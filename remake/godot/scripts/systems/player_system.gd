extends Node

# 信号定义
signal session_initialized(session_key: String, players: Array)
signal current_player_changed(player: COM_PlayerInst)
signal player_created(player: COM_SimpleInformation)
signal player_deleted(name: String)

# 数据存储
var _session_key: String = ""
var _current: COM_PlayerInst = null
var _players: Array[COM_SimpleInformation] = []

# 初始化会话
func init_session(session_key: String, players: Array) -> void:
	_session_key = session_key
	_players = players
	session_initialized.emit(session_key, players)

# 设置当前角色
func set_current_player(player: COM_PlayerInst) -> void:
	_current = player
	current_player_changed.emit(player)

# 添加角色
func add_player(player: COM_SimpleInformation) -> void:
	_players.append(player)
	player_created.emit(player)

# 删除角色
func remove_player(name: String) -> void:
	for i in range(_players.size()):
		if _players[i].instName_ == name:
			_players.remove_at(i)
			player_deleted.emit(name)
			break

# 查询方法
func get_current() -> COM_PlayerInst:
	return _current

func get_players() -> Array[COM_SimpleInformation]:
	return _players

func get_session_key() -> String:
	return _session_key

func get_player_by_id(inst_id: int) -> COM_SimpleInformation:
	for player in _players:
		if player.instId_ == inst_id:
			return player
	return null

func get_player_count() -> int:
	return _players.size()

# 更新当前玩家属性
func update_properties(props: Array[COM_PropValue]) -> void:
	if _current == null:
		return
	EntityUtils.update_properties(_current, props)
	current_player_changed.emit(_current)

# ========== 使用 PropertyType 枚举获取属性（通过 EntityUtils）==========

# 获取当前玩家等级
func get_level() -> int:
	return EntityUtils.get_level(_current)

# 获取当前玩家HP
func get_hp() -> int:
	return EntityUtils.get_hp(_current)

func get_hp_max() -> int:
	return EntityUtils.get_hp_max(_current)

# 获取当前玩家HP百分比
func get_hp_percent() -> float:
	return EntityUtils.get_hp_percent(_current)

# 获取当前玩家MP
func get_mp() -> int:
	return EntityUtils.get_mp(_current)

func get_mp_max() -> int:
	return EntityUtils.get_mp_max(_current)

# 获取当前玩家MP百分比
func get_mp_percent() -> float:
	return EntityUtils.get_mp_percent(_current)

# 获取当前玩家经验
func get_exp() -> int:
	return EntityUtils.get_exp(_current)

# 获取金币
func get_money() -> int:
	return EntityUtils.get_money(_current)

# 获取攻击力
func get_attack() -> int:
	return EntityUtils.get_attack(_current)

# 获取防御力
func get_defense() -> int:
	return EntityUtils.get_defense(_current)

# 获取魔法攻击
func get_magic_attack() -> int:
	return EntityUtils.get_magic_attack(_current)

# 获取魔法防御
func get_magic_defense() -> int:
	return EntityUtils.get_magic_defense(_current)

# 检查是否存活
func is_alive() -> bool:
	return EntityUtils.is_alive(_current)
