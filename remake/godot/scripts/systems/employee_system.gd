extends Node

# 信号定义
signal employees_initialized(employees: Array, is_flag: bool)
signal battle_group_initialized(group: COM_BattleEmp)
signal employee_added(employee: COM_EmployeeInst)
signal employee_removed(inst_ids: Array)
signal employee_updated(employee: COM_EmployeeInst)
signal battle_group_changed(group: int)
signal employee_evolved(inst_id: int, quality: int)
signal employee_star_upped(inst_id: int, star: int, skill: COM_Skill)
signal employee_soul_changed(inst_id: int, soul_num: int)
signal employee_properties_updated(inst_id: int)

# 数据存储
var _employees: Array[COM_EmployeeInst] = []
var _battle_group: COM_BattleEmp = null

# 初始化
func init_employees(employees: Array, is_flag: bool) -> void:
	_employees = employees
	employees_initialized.emit(employees, is_flag)

func init_battle_group(group: COM_BattleEmp) -> void:
	_battle_group = group
	battle_group_initialized.emit(group)

# 列表操作
func add_employee(employee: COM_EmployeeInst) -> void:
	_employees.append(employee)
	employee_added.emit(employee)

func remove_employees(inst_ids: Array) -> void:
	for inst_id in inst_ids:
		for i in range(_employees.size()):
			if _employees[i].instId_ == inst_id:
				_employees.remove_at(i)
				break
	employee_removed.emit(inst_ids)

func update_employee(employee: COM_EmployeeInst) -> void:
	for i in range(_employees.size()):
		if _employees[i].instId_ == employee.instId_:
			_employees[i] = employee
			employee_updated.emit(employee)
			break

func get_employee(inst_id: int) -> COM_EmployeeInst:
	for emp in _employees:
		if emp.instId_ == inst_id:
			return emp
	return null

func get_employees() -> Array[COM_EmployeeInst]:
	return _employees

# 战斗队伍
func set_battle_employee(emp_id: int, group: int, for_battle: bool) -> void:
	for emp in _employees:
		if emp.instId_ == emp_id:
			emp.isBattle_ = for_battle
			break
	battle_group_changed.emit(group)

func change_battle_group(group: int) -> void:
	battle_group_changed.emit(group)

# 成长操作
func evolve_employee(inst_id: int, quality: int) -> void:
	for emp in _employees:
		if emp.instId_ == inst_id:
			emp.quality_ = quality
			break
	employee_evolved.emit(inst_id, quality)

func up_star_employee(inst_id: int, star: int, skill: COM_Skill) -> void:
	for emp in _employees:
		if emp.instId_ == inst_id:
			emp.star_ = star
			break
	employee_star_upped.emit(inst_id, star, skill)

func update_soul(inst_id: int, soul_num: int) -> void:
	for emp in _employees:
		if emp.instId_ == inst_id:
			emp.soul_ = soul_num
			break
	employee_soul_changed.emit(inst_id, soul_num)

# 查询
func get_employee_by_id(inst_id: int) -> COM_EmployeeInst:
	for emp in _employees:
		if emp.instId_ == inst_id:
			return emp
	return null

func get_battle_group() -> COM_BattleEmp:
	return _battle_group

func get_employee_count() -> int:
	return _employees.size()

func get_battle_employees() -> Array[COM_EmployeeInst]:
	var battle_emps: Array[COM_EmployeeInst] = []
	for emp in _employees:
		if emp.isBattle_:
			battle_emps.append(emp)
	return battle_emps

# 更新员工属性
func update_properties(inst_id: int, props: Array[COM_PropValue]) -> void:
	var emp = get_employee_by_id(inst_id)
	if emp == null:
		print("警告: EmployeeSystem.update_properties - 找不到员工: ", inst_id)
		return

	EntityUtils.update_properties(emp, props)
	employee_properties_updated.emit(inst_id)

# ========== 使用 PropertyType 枚举获取属性（通过 EntityUtils）==========

# 通过 ID 获取员工属性
func get_property_by_id(emp_id: int, property_type: int) -> float:
	var emp = get_employee_by_id(emp_id)
	return EntityUtils.get_property(emp, property_type)

# 获取员工等级
func get_level(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_level(emp)

# 获取员工HP
func get_hp(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_hp(emp)

func get_hp_max(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_hp_max(emp)

# 获取员工HP百分比
func get_hp_percent(emp: COM_EmployeeInst) -> float:
	return EntityUtils.get_hp_percent(emp)

# 获取员工MP
func get_mp(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_mp(emp)

func get_mp_max(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_mp_max(emp)

# 获取员工MP百分比
func get_mp_percent(emp: COM_EmployeeInst) -> float:
	return EntityUtils.get_mp_percent(emp)

# 获取员工攻击力
func get_attack(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_attack(emp)

# 获取员工防御力
func get_defense(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_defense(emp)

# 获取员工魔法攻击
func get_magic_attack(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_magic_attack(emp)

# 获取员工魔法防御
func get_magic_defense(emp: COM_EmployeeInst) -> int:
	return EntityUtils.get_magic_defense(emp)

# 检查员工是否存活
func is_alive(emp: COM_EmployeeInst) -> bool:
	return EntityUtils.is_alive(emp)

# 获取员工品质（从直接字段获取）
func get_quality(emp: COM_EmployeeInst) -> int:
	return emp.quality_ if emp != null else 0

# 获取员工星级（从直接字段获取）
func get_star(emp: COM_EmployeeInst) -> int:
	return emp.star_ if emp != null else 0

# 获取员工魂力
func get_soul(emp: COM_EmployeeInst) -> int:
	return emp.soul_ if emp != null else 0
