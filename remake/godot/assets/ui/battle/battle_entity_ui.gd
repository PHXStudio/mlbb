extends Control
class_name BattleEntityUI

@onready var background = $Background
@onready var name_label = $NameLabel
@onready var hp_bar = $HPBar
@onready var hp_text = $HPText
@onready var mp_bar = $MPBar
@onready var sprite = $Sprite

var _entity

func setup(entity) -> void:
	_entity = entity
	if _entity.has_method("get_display_name"):
		name_label.text = _entity.get_display_name()
	else:
		name_label.text = _entity.instName_
	_update_hp_mp()

func update_from_entity(entity) -> void:
	_entity = entity
	_update_hp_mp()

func _update_hp_mp() -> void:
	if _entity == null:
		return

	var hp_max = 0
	var hp_crt = 0
	var mp_max = 0
	var mp_crt = 0
	var position = -1
	if _entity.has_method("get_hp_percent"):
		hp_max = _entity.hp_max
		hp_crt = _entity.hp_current
		mp_max = _entity.mp_max
		mp_crt = _entity.mp_current
		position = _entity.position
	else:
		hp_max = _entity.get_hpMax_()
		hp_crt = _entity.get_hpCrt_()
		mp_max = _entity.get_mpMax_()
		mp_crt = _entity.get_mpCrt_()
		position = _entity.battlePosition_

	if hp_max > 0:
		hp_bar.value = float(hp_crt) / float(hp_max) * 100.0
	hp_text.text = str(hp_crt) + "/" + str(hp_max)

	if mp_max > 0:
		mp_bar.value = float(mp_crt) / float(mp_max) * 100.0

	# 根据阵营设置不同颜色
	if BattleSystem.is_my_team(position):
		background.color = Color(0.1, 0.3, 0.1, 0.8)  # 绿色背景（我方）
	else:
		background.color = Color(0.4, 0.1, 0.1, 0.8)  # 红色背景（敌方）

func show_damage(amount: int, is_critical: bool) -> void:
	# 显示伤害数字动画
	var damage_label = Label.new()
	damage_label.text = "-" + str(amount)
	damage_label.position = Vector2(50, 20)
	damage_label.z_index = 10

	if is_critical:
		damage_label.add_theme_color_override("font_color", Color.RED)
		damage_label.add_theme_font_size_override("font_size", 24)
	else:
		damage_label.add_theme_color_override("font_color", Color.WHITE)

	add_child(damage_label)

	# 创建飘字动画
	var tween = create_tween()
	tween.parallel().tween_property(damage_label, "position:y", -20, 0.5)
	tween.parallel().tween_property(damage_label, "modulate:a", 0.0, 0.5)
	tween.tween_callback(damage_label.queue_free)

func show_heal(amount: int) -> void:
	# 显示治疗数字动画
	var heal_label = Label.new()
	heal_label.text = "+" + str(amount)
	heal_label.position = Vector2(50, 20)
	heal_label.z_index = 10
	heal_label.add_theme_color_override("font_color", Color.GREEN)

	add_child(heal_label)

	var tween = create_tween()
	tween.parallel().tween_property(heal_label, "position:y", -20, 0.5)
	tween.parallel().tween_property(heal_label, "modulate:a", 0.0, 0.5)
	tween.tween_callback(heal_label.queue_free)

func show_death() -> void:
	# 死亡效果
	modulate = Color(0.3, 0.3, 0.3, 0.5)

func is_my_team() -> bool:
	if _entity == null:
		return false
	if _entity.has_method("get_hp_percent"):
		return BattleSystem.is_my_team(_entity.position)
	return BattleSystem.is_my_team(_entity.battlePosition_)
