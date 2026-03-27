extends Node


# 玩家模板信息类
class PlayerTemplateInfo:
	var id: int
	var sex: int           # 1=男, 2=女
	var asset_id: int      # 3D外观ID
	var race: String       # 种族名称
	var race_desc: String  # 种族描述
	var race_icon: String  # 种族图标

	# 初始属性
	var stamina: int    # 体力(PT_Stama)
	var strength: int   # 力量(PT_Strength)
	var power: int      # 力量(PT_Power)
	var speed: int      # 敏捷(PT_Speed)
	var magic: int      # 智力(PT_Magic)

	func _init(p_id: int, p_sex: int, p_asset_id: int, p_race: String, p_race_desc: String,
				  p_race_icon: String, p_stamina: int, p_strength: int, p_power: int, p_speed: int, p_magic: int):
		id = p_id
		sex = p_sex
		asset_id = p_asset_id
		race = p_race
		race_desc = p_race_desc
		race_icon = p_race_icon
		stamina = p_stamina
		strength = p_strength
		power = p_power
		speed = p_speed
		magic = p_magic

# 从 PlayerData.csv 提取的模板数据
# 格式: ID, sex, PT_AssetId, Race, race_decs, RaceIcon, PT_Stama, PT_Strength, PT_Power, PT_Speed, PT_Magic
var _templates: Array[PlayerTemplateInfo] = [
	# 男性模板
	PlayerTemplateInfo.new(1, 1, 1, "诺特人", "诺特人，主要的集中地其实是在贝伦大陆北方的雪域之中，但也会有很多诺特人会南下，来到气候更为温和地方生活，诺特人可谓是骁勇善战的代名词，他们天生拥有过人的体质以及无畏的精神。", "cw_xiao_shuxing1", 6, 6, 6, 6, 6),
	PlayerTemplateInfo.new(2, 1, 103, "卡塔利亚人", "卡塔利亚人，贝伦大陆西部的主要种族群体，卡塔利亚人可谓是遍布贝伦大陆整个西部，卡塔利亚人身材较一般人要稍微矮小一些，体质也没那么强健，但他们有着过人的智慧，卡塔利亚人常年受到皇国——格拉维斯特的压迫，直到一个名为诺兰的卡塔利亚人在贝伦大陆西部靠北的地方建立了教国——阿卡利亚，卡塔利亚人才逐渐的从压迫中翻身。", "cw_xiao_shuxing1", 6, 6, 6, 6, 6),
	PlayerTemplateInfo.new(3, 1, 104, "摩罗拉斯人", "摩罗拉斯人，散落生活在贝伦大陆西部各地，摩罗拉斯人通常都是敏捷的，他们大多数人都是才能突出的刺客，佣兵，摩罗拉斯人非常喜欢钱财，而他们的道德观念也与传统道德观念不符。", "cw_xiao_shuxing1", 6, 6, 6, 6, 6),
	# 女性模板
	PlayerTemplateInfo.new(4, 2, 101, "林度人", "林度人，主要生活在贝伦大陆中部，在贝伦大陆西部，会有稀少的林度人出现，林度人是一个习惯自由的种族，很多林度人以部落为生存群体，林度人比别的种族的人类都要高挑，耳朵也较一般人类要长一些。", "cw_xiao_shuxing1", 6, 6, 6, 6, 6),
	PlayerTemplateInfo.new(5, 2, 102, "菲尼克斯人", "菲尼克斯人，散落在贝伦大陆各地，他们主要喜欢在海港城镇居住，菲尼克斯人通常都是非常善水的，菲尼克斯人最大的群体居住地是贝伦大陆西部偏西南脱离贝伦大陆本体的海岛国家奥克罗蒂亚。", "cw_xiao_shuxing1", 6, 6, 6, 6, 6),
	PlayerTemplateInfo.new(6, 2, 12, "暗月裔人", "暗月裔人，传说住在遥远东方国度的种族，在贝伦大陆，只有非常稀少的暗月裔人存在，他们通常是隐藏在阴暗处，很少会暴露在众目睽睽当中，这是暗月裔人的行事风格，少言寡语，却异常致命。", "cw_xiao_shuxing1", 6, 6, 6, 6, 6),
]

# 获取所有模板
func get_all_templates() -> Array[PlayerTemplateInfo]:
	return _templates

# 根据ID获取模板
func get_template_by_id(id: int) -> PlayerTemplateInfo:
	for template in _templates:
		if template.id == id:
			return template
	return null

# 根据性别获取模板
func get_templates_by_sex(sex: int) -> Array[PlayerTemplateInfo]:
	var result: Array[PlayerTemplateInfo] = []
	for template in _templates:
		if template.sex == sex:
			result.append(template)
	return result

# 获取男性模板
func get_male_templates() -> Array[PlayerTemplateInfo]:
	return get_templates_by_sex(1)

# 获取女性模板
func get_female_templates() -> Array[PlayerTemplateInfo]:
	return get_templates_by_sex(2)
