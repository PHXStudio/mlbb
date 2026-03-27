extends RefCounted
class_name BattleEntity

var inst_id: int = 0
var position: int = -1
var name: String = ""
var hp_current: int = 0
var hp_max: int = 0
var mp_current: int = 0
var mp_max: int = 0
var is_dead: bool = false
var is_my_team: bool = false

static func create(entity_info: COM_BattleEntityInformation, my_team: bool) -> BattleEntity:
	var entity = BattleEntity.new()
	entity.is_my_team = my_team
	entity.update_from_entity_info(entity_info)
	return entity

func get_display_name() -> String:
	if name.is_empty():
		return "Unknown"
	return name

func get_hp_percent() -> float:
	if hp_max <= 0:
		return 0.0
	return float(hp_current) / float(hp_max) * 100.0

func get_mp_percent() -> float:
	if mp_max <= 0:
		return 0.0
	return float(mp_current) / float(mp_max) * 100.0

func is_alive() -> bool:
	return hp_current > 0

func take_damage(amount: int) -> void:
	hp_current = max(0, hp_current - max(0, amount))
	is_dead = hp_current <= 0

func heal(amount: int) -> void:
	hp_current = min(hp_max, hp_current + max(0, amount))
	is_dead = hp_current <= 0

func update_from_entity_info(entity_info: COM_BattleEntityInformation) -> void:
	if entity_info == null:
		return

	inst_id = entity_info.instId_
	position = entity_info.battlePosition_
	name = entity_info.instName_
	hp_current = entity_info.hpCrt_
	hp_max = entity_info.hpMax_
	mp_current = entity_info.mpCrt_
	mp_max = entity_info.mpMax_
	is_dead = hp_current <= 0

func update_from_report_target(target: COM_ReportTarget) -> Dictionary:
	var change := {"hp_delta": 0, "mp_delta": 0}
	if target == null:
		return change

	var previous_hp = hp_current
	var previous_mp = mp_current

	if target.has_method("get_hpCrt_"):
		hp_current = target.get_hpCrt_()
	if target.has_method("get_mpCrt_"):
		mp_current = target.get_mpCrt_()

	change.hp_delta = hp_current - previous_hp
	change.mp_delta = mp_current - previous_mp
	is_dead = hp_current <= 0
	return change
