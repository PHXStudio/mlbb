extends Node

# 信号定义
signal bag_initialized(items: Array)
signal storage_initialized(grid_num: int, items: Array)
signal equips_initialized(items: Array)
signal item_added(item: COM_Item)
signal item_removed(slot: int)
signal item_updated(item: COM_Item)
signal item_deposited(item: COM_Item)
signal item_withdrawn(item: COM_Item)
signal equipment_worn(target: int, equip: COM_Item)
signal equipment_removed(target: int, item_id: int)
signal bag_sorted()
signal storage_sorted(items: Array)
signal storage_grid_opened(grid_num: int)

# 数据存储
var _bag_items: Array[COM_Item] = []
var _item_storage: Array[COM_Item] = []
var _item_storage_grid_num: int = 0
var _player_equips: Array[COM_Item] = []  # 6 equipment slots

# 初始化
func init_bag(items: Array) -> void:
	_bag_items = items
	bag_initialized.emit(items)

func init_storage(grid_num: int, items: Array) -> void:
	_item_storage_grid_num = grid_num
	_item_storage = items
	storage_initialized.emit(grid_num, items)

func init_equips(items: Array) -> void:
	_player_equips = items
	equips_initialized.emit(items)

# 背包操作
func add_item(item: COM_Item) -> void:
	_bag_items.append(item)
	item_added.emit(item)

func remove_item(slot: int) -> void:
	for i in range(_bag_items.size()):
		if _bag_items[i].slot_ == slot:
			_bag_items.remove_at(i)
			item_removed.emit(slot)
			break

func update_item(item: COM_Item) -> void:
	for i in range(_bag_items.size()):
		if _bag_items[i].slot_ == item.slot_:
			_bag_items[i] = item
			item_updated.emit(item)
			break

func get_item_by_slot(slot: int) -> COM_Item:
	for item in _bag_items:
		if item.slot_ == slot:
			return item
	return null

func get_items() -> Array[COM_Item]:
	return _bag_items

func sort_bag() -> void:
	bag_sorted.emit()

# 仓库操作
func deposit_item(item: COM_Item) -> void:
	_item_storage.append(item)
	item_deposited.emit(item)

func withdraw_item(slot: int) -> void:
	for i in range(_item_storage.size()):
		if _item_storage[i].slot_ == slot:
			var item = _item_storage[i]
			_item_storage.remove_at(i)
			_bag_items.append(item)
			item_withdrawn.emit(item)
			break

func sort_storage(items: Array) -> void:
	_item_storage = items
	storage_sorted.emit(items)

func open_storage_grid(grid_num: int) -> void:
	_item_storage_grid_num = grid_num
	storage_grid_opened.emit(grid_num)

# 装备操作
func wear_equipment(target: int, equip: COM_Item) -> void:
	var equip_slot = equip.equipType_ if equip.has_method("get_equipType_") else -1
	if equip_slot >= 0 and equip_slot < _player_equips.size():
		_player_equips[equip_slot] = equip
	equipment_worn.emit(target, equip)

func remove_equipment(target: int, item_id: int) -> void:
	for i in range(_player_equips.size()):
		if _player_equips[i] != null and _player_equips[i].instId_ == item_id:
			_player_equips[i] = null
			equipment_removed.emit(target, item_id)
			break

# 查询
func get_item_by_id(item_id: int) -> COM_Item:
	for item in _bag_items:
		if item.instId_ == item_id:
			return item
	for item in _item_storage:
		if item.instId_ == item_id:
			return item
	for item in _player_equips:
		if item != null and item.instId_ == item_id:
			return item
	return null

func get_items_by_type(item_type: int) -> Array[COM_Item]:
	var result: Array[COM_Item] = []
	for item in _bag_items:
		if item.itemId_ == item_type:
			result.append(item)
	return result

func get_equips() -> Array[COM_Item]:
	return _player_equips

func get_storage_items() -> Array[COM_Item]:
	return _item_storage

func get_storage_grid_num() -> int:
	return _item_storage_grid_num

func get_bag_count() -> int:
	return _bag_items.size()

func get_storage_count() -> int:
	return _item_storage.size()

# 辅助方法
func find_empty_bag_slot() -> int:
	var used_slots: Array[int] = []
	for item in _bag_items:
		used_slots.append(item.slot_)
	used_slots.sort()
	for i in range(used_slots.size()):
		if used_slots[i] != i:
			return i
	return used_slots.size()

func find_empty_storage_slot() -> int:
	var used_slots: Array[int] = []
	for item in _item_storage:
		used_slots.append(item.slot_)
	used_slots.sort()
	for i in range(used_slots.size()):
		if used_slots[i] != i:
			return i
	return used_slots.size()
