extends Node

# 信号定义
signal babies_initialized(babies: Array)
signal storage_initialized(grid_num: int, babies: Array)
signal baby_added(baby: COM_BabyInst)
signal baby_removed(baby_id: int)
signal baby_updated(baby: COM_BabyInst)
signal baby_deposited(baby: COM_BabyInst)
signal baby_withdrawn(baby: COM_BabyInst)
signal baby_name_changed(baby_id: int, name: String)
signal baby_remolded(baby_id: int)
signal baby_intensified(baby_id: int, intensify_level: int)
signal baby_properties_updated(baby_id: int)
signal storage_sorted(babies: Array)
signal storage_grid_opened(grid_num: int)
signal storage_baby_removed(slot: int)

# 数据存储
var _babies: Array[COM_BabyInst] = []
var _baby_storage: Array[COM_BabyInst] = []
var _baby_storage_grid_num: int = 0

# 初始化
func init_babies(babies: Array) -> void:
	_babies = babies
	babies_initialized.emit(babies)

func init_storage(grid_num: int, babies: Array) -> void:
	_baby_storage_grid_num = grid_num
	_baby_storage = babies
	storage_initialized.emit(grid_num, babies)

# 列表操作
func add_baby(baby: COM_BabyInst) -> void:
	_babies.append(baby)
	baby_added.emit(baby)

func remove_baby(baby_id: int) -> void:
	for i in range(_babies.size()):
		if _babies[i].instId_ == baby_id:
			_babies.remove_at(i)
			baby_removed.emit(baby_id)
			break

func update_baby(baby: COM_BabyInst) -> void:
	for i in range(_babies.size()):
		if _babies[i].instId_ == baby.instId_:
			_babies[i] = baby
			baby_updated.emit(baby)
			break

func get_baby(baby_id: int) -> COM_BabyInst:
	for baby in _babies:
		if baby.instId_ == baby_id:
			return baby
	for baby in _baby_storage:
		if baby.instId_ == baby_id:
			return baby
	return null

func get_babies() -> Array[COM_BabyInst]:
	return _babies

# 仓库操作
func deposit_baby(baby: COM_BabyInst) -> void:
	# 从列表中移除
	for i in range(_babies.size()):
		if _babies[i].instId_ == baby.instId_:
			_babies.remove_at(i)
			break
	# 添加到仓库
	_baby_storage.append(baby)
	baby_deposited.emit(baby)

func withdraw_baby(slot: int) -> void:
	for i in range(_baby_storage.size()):
		if _baby_storage[i].slot_ == slot:
			var baby = _baby_storage[i]
			_baby_storage.remove_at(i)
			_babies.append(baby)
			baby_withdrawn.emit(baby)
			break

func remove_storage_baby(slot: int) -> void:
	for i in range(_baby_storage.size()):
		if _baby_storage[i].slot_ == slot:
			_baby_storage.remove_at(i)
			storage_baby_removed.emit(slot)
			break

func sort_storage(babies: Array) -> void:
	_baby_storage = babies
	storage_sorted.emit(babies)

func open_storage_grid(grid_num: int) -> void:
	_baby_storage_grid_num = grid_num
	storage_grid_opened.emit(grid_num)

# 特殊操作
func change_name(baby_id: int, name: String) -> void:
	for baby in _babies:
		if baby.instId_ == baby_id:
			baby.instName_ = name
			baby_name_changed.emit(baby_id, name)
			break
	for baby in _baby_storage:
		if baby.instId_ == baby_id:
			baby.instName_ = name
			baby_name_changed.emit(baby_id, name)
			break

func remold(baby_id: int) -> void:
	baby_remolded.emit(baby_id)

func intensify(baby_id: int, intensify_level: int) -> void:
	for baby in _babies:
		if baby.instId_ == baby_id:
			baby.intensifyLevel_ = intensify_level
			baby_intensified.emit(baby_id, intensify_level)
			break
	for baby in _baby_storage:
		if baby.instId_ == baby_id:
			baby.intensifyLevel_ = intensify_level
			baby_intensified.emit(baby_id, intensify_level)
			break

# 查询
func get_baby_by_id(baby_id: int) -> COM_BabyInst:
	for baby in _babies:
		if baby.instId_ == baby_id:
			return baby
	for baby in _baby_storage:
		if baby.instId_ == baby_id:
			return baby
	return null

func get_babies_in_storage() -> Array[COM_BabyInst]:
	return _baby_storage

func get_storage_grid_num() -> int:
	return _baby_storage_grid_num

func get_baby_count() -> int:
	return _babies.size()

func get_storage_count() -> int:
	return _baby_storage.size()

# 更新宝宝属性
func update_properties(baby_id: int, props: Array[COM_PropValue]) -> void:
	var baby = get_baby_by_id(baby_id)
	if baby == null:
		print("警告: BabySystem.update_properties - 找不到宝宝: ", baby_id)
		return

	EntityUtils.update_properties(baby, props)
	baby_properties_updated.emit(baby_id)

# ========== 使用 PropertyType 枚举获取属性（通过 EntityUtils）==========

# 通过 ID 获取宝宝属性
func get_property_by_id(baby_id: int, property_type: int) -> float:
	var baby = get_baby_by_id(baby_id)
	return EntityUtils.get_property(baby, property_type)

# 获取宝宝等级
func get_level(baby: COM_BabyInst) -> int:
	return EntityUtils.get_level(baby)

# 获取宝宝HP
func get_hp(baby: COM_BabyInst) -> int:
	return EntityUtils.get_hp(baby)

func get_hp_max(baby: COM_BabyInst) -> int:
	return EntityUtils.get_hp_max(baby)

# 获取宝宝HP百分比
func get_hp_percent(baby: COM_BabyInst) -> float:
	return EntityUtils.get_hp_percent(baby)

# 获取宝宝MP
func get_mp(baby: COM_BabyInst) -> int:
	return EntityUtils.get_mp(baby)

func get_mp_max(baby: COM_BabyInst) -> int:
	return EntityUtils.get_mp_max(baby)

# 获取宝宝MP百分比
func get_mp_percent(baby: COM_BabyInst) -> float:
	return EntityUtils.get_mp_percent(baby)

# 获取宝宝经验
func get_exp(baby: COM_BabyInst) -> int:
	return EntityUtils.get_exp(baby)

# 检查宝宝是否存活
func is_alive(baby: COM_BabyInst) -> bool:
	return EntityUtils.is_alive(baby)
