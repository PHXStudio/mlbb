extends RefCounted
class_name BattleReportParser

const ACTION_ATTACK := "attack"
const ACTION_HEAL := "heal"
const ACTION_STATE_CHANGE := "state_change"
const ACTION_WAVE_ENTITY := "wave_entity"

# 解析完整战报，返回统一 BattleAction 队列
func parse_report(report: COM_BattleReport, turn_index: int) -> Array[Dictionary]:
	var actions: Array[Dictionary] = []
	if report == null:
		return actions

	var actor_id := 0
	if report.has_method("get_instId_"):
		actor_id = report.get_instId_()

	if report.targets_ != null:
		for target in report.targets_:
			var parsed = _parse_target_action(target, actor_id, turn_index)
			if not parsed.is_empty():
				actions.append(parsed)

	if report.stateIds_ != null:
		for state_id in report.stateIds_:
			actions.append({
				"action_type": ACTION_STATE_CHANGE,
				"actor_id": actor_id,
				"target_id": 0,
				"target_position": -1,
				"hp_delta": 0,
				"mp_delta": 0,
				"is_critical": false,
				"turn_index": turn_index,
				"state_id": state_id,
				"raw_ref": report
			})

	if report.waveEntities_ != null:
		for entity in report.waveEntities_:
			actions.append({
				"action_type": ACTION_WAVE_ENTITY,
				"actor_id": actor_id,
				"target_id": 0,
				"target_position": -1,
				"hp_delta": 0,
				"mp_delta": 0,
				"is_critical": false,
				"turn_index": turn_index,
				"entity_info": entity,
				"raw_ref": report
			})

	return actions

# 解析HP变化
func parse_hp_change(target: COM_ReportTarget) -> Dictionary:
	var result = {"damage": 0, "heal": 0}

	if target == null:
		return result

	# 尝试从属性中获取HP变化
	if target.has_method("get_prop_"):
		var prop = target.get_prop_()
		if prop != null:
			var prop_type = prop.get_type_()
			var value = int(prop.get_value_())
			if prop_type == PropertyType.PT_HpCurr:  # HP属性
				if value < 0:
					result.damage = -value
				else:
					result.heal = value

	return result

# 判断是否暴击
func is_critical_hit(target: COM_ReportTarget) -> bool:
	if target != null and target.has_method("get_critical_"):
		return target.get_critical_()
	return false

# 获取行动描述
func get_action_description(action: COM_ReportAction) -> String:
	if action == null:
		return "未知行动"

	var desc = ""

	# 根据行动类型返回描述
	if action.has_method("get_skillId_"):
		var skill_id = action.get_skillId_()
		desc = "使用技能 " + str(skill_id)
	elif action.has_method("get_itemId_"):
		var item_id = action.get_itemId_()
		desc = "使用物品 " + str(item_id)
	else:
		desc = "普通攻击"

	return desc

func _parse_target_action(target: COM_ReportTarget, actor_id: int, turn_index: int) -> Dictionary:
	if target == null:
		return {}

	var target_position := -1
	if target.has_method("get_position_"):
		target_position = target.get_position_()

	var target_id := 0
	if target.has_method("get_instId_"):
		target_id = target.get_instId_()

	var hp_delta := 0
	var mp_delta := 0
	if target.has_method("get_hpChange_"):
		hp_delta = target.get_hpChange_()
	elif target.has_method("get_hpDelta_"):
		hp_delta = target.get_hpDelta_()
	if target.has_method("get_mpChange_"):
		mp_delta = target.get_mpChange_()
	elif target.has_method("get_mpDelta_"):
		mp_delta = target.get_mpDelta_()

	var action_type = ACTION_ATTACK
	if hp_delta > 0:
		action_type = ACTION_HEAL

	return {
		"action_type": action_type,
		"actor_id": actor_id,
		"target_id": target_id,
		"target_position": target_position,
		"hp_delta": hp_delta,
		"mp_delta": mp_delta,
		"is_critical": is_critical_hit(target),
		"turn_index": turn_index,
		"raw_ref": target
	}
