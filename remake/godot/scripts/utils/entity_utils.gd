class_name EntityUtils

# 通用的实体属性获取方法
# entity: COM_Entity 及其派生类 (COM_PlayerInst, COM_BabyInst, COM_EmployeeInst)

# 获取实体指定属性值
static func get_property(entity: COM_Entity, property_type: int) -> float:
	if entity == null:
		return 0.0

	var properties = entity.properties_
	if properties == null or property_type < 0 or property_type >= properties.size():
		return 0.0

	return properties[property_type]

# 设置实体指定属性值
static func set_property(entity: COM_Entity, property_type: int, value: float) -> void:
	if entity == null:
		return

	var properties = entity.properties_
	if properties == null:
		return

	# 确保数组足够大
	while properties.size() <= property_type:
		properties.append(0.0)

	properties[property_type] = value
	entity.properties_ = properties

# 验证属性类型是否有效
static func is_valid_property_type(property_type: int) -> bool:
	return property_type >= 0 and property_type < PropertyType.PT_Max

# ========== 通用属性获取方法 ==========

# 获取等级
static func get_level(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Level))

# 获取经验值
static func get_exp(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Exp))

# HP 相关
static func get_hp(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_HpCurr))

static func get_hp_max(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_HpMax))

static func get_hp_percent(entity: COM_Entity) -> float:
	var hp_max = get_hp_max(entity)
	if hp_max > 0:
		return float(get_hp(entity)) / float(hp_max) * 100.0
	return 0.0

# MP 相关
static func get_mp(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_MpCurr))

static func get_mp_max(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_MpMax))

static func get_mp_percent(entity: COM_Entity) -> float:
	var mp_max = get_mp_max(entity)
	if mp_max > 0:
		return float(get_mp(entity)) / float(mp_max) * 100.0
	return 0.0

# 战斗属性
static func get_attack(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Attack))

static func get_defense(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Defense))

static func get_magic_attack(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Magicattack))

static func get_magic_defense(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Magicdefense))

# 货币相关
static func get_money(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Money))

static func get_diamond(entity: COM_Entity) -> int:
	return int(get_property(entity, PropertyType.PT_Diamond))

# 检查实体是否存活
static func is_alive(entity: COM_Entity) -> bool:
	return get_hp(entity) > 0

# ========== 属性更新方法 ==========

# 更新实体属性（通用方法）
static func update_properties(entity: COM_Entity, props: Array[COM_PropValue]) -> void:
	if entity == null:
		return

	var properties = entity.properties_
	var updated = false

	for prop in props:
		if prop == null:
			continue

		var prop_type = prop.type_
		var prop_value = prop.value_

		# 验证属性类型
		if not is_valid_property_type(prop_type):
			print("警告: EntityUtils - 无效的属性类型: ", prop_type)
			continue

		# 确保数组足够大
		while properties.size() <= prop_type:
			properties.append(0.0)

		# 更新属性值
		properties[prop_type] = prop_value
		updated = true

	if updated:
		entity.properties_ = properties

# 批量更新属性（字典形式）
static func update_properties_dict(entity: COM_Entity, props_dict: Dictionary) -> void:
	if entity == null:
		return

	var properties = entity.get_properties()

	for prop_type in props_dict:
		var value = props_dict[prop_type]
		if is_valid_property_type(prop_type):
			while properties.size() <= prop_type:
				properties.append(0.0)
			properties[prop_type] = float(value)

	entity.properties_ = properties

# ========== 实体信息获取 ==========

# 获取实体显示名称
static func get_name(entity: COM_Entity) -> String:
	if entity == null:
		return "Unknown"
	return entity.instName_

# 获取实体 ID
static func get_inst_id(entity: COM_Entity) -> int:
	if entity == null:
		return 0
	return entity.instId_

# 获取实体类型
static func get_type(entity: COM_Entity) -> int:
	if entity == null:
		return 0
	return entity.type_
