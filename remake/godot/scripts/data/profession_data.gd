extends Node


# 职业信息类
class ProfessionInfo:
	var id: int
	var name: String
	var description: String
	var job_type: String  # JobType enum string

	func _init(p_id: int, p_name: String, p_desc: String, p_job_type: String):
		id = p_id
		name = p_name
		description = p_desc
		job_type = p_job_type

# 所有职业数据（从 ProfessionData.csv 提取）
var _all_professions: Array[ProfessionInfo] = [
	ProfessionInfo.new(1, "游民", "", "JT_Newbie"),
	ProfessionInfo.new(2, "见习佣兵", "挥舞著明晃晃的大斧，以终极重力横扫著一群一群的敌人，佣兵是各职业中攻最高的，想体验高战斗能力的你佣兵是你最好的选择！", "JT_Axe"),
	ProfessionInfo.new(3, "见习剑士", "挥动著手中的圣剑，毫不留情的斩杀所有危害善良的邪恶魔物…剑是武器中的君子，剑士就可谓是战士中的强者，不妨试下，去体验英雄的滋味。", "JT_Sword"),
	ProfessionInfo.new(4, "见习骑士", "拥有高尚的骑士精神，绝不允许别人伤害自己队友的热血…超高的防御力让骑士成为战斗中最难缠的角色之一。喜欢刀枪不入的你，骑士就是你最佳的选择!", "JT_Knight"),
	ProfessionInfo.new(5, "见习猎人", "藏匿在隐密的地点，优雅的取出箭矢搭在弓上，精准瞄准著敌人的心脏，手起矢出，敌人应声而倒…难度小，适合刚进大陆的你。", "JT_Archer"),
	ProfessionInfo.new(6, "见习武僧", "赤手空拳将敌人击败在自己的拳头之上…格斗空手的威力比其它职业的要大。想体验战斗系技能的精髓的你，就尝试这个职业吧。", "JT_Fighter"),
	ProfessionInfo.new(7, "初级刺客", "漂亮的刺杀，通常可以一轮把对方带走，赢得队友羡慕的眼光…喜欢向难度挑战的玩家可以选择刺客这个职业。", "JT_Ninja"),
	ProfessionInfo.new(10, "见习法师", "吟唱着古老的咒文，释放出强大的精神力，以毁灭性的魔法将眼前的敌人带入死亡的地狱…如果你想体验群攻强大的魔法威力，就选择法师吧。", "JT_Mage"),
	ProfessionInfo.new(11, "见习牧师", "默念着回复体力的神圣咒文，让身受重伤的队友重新站起来，永远在后面支持着队友…如果你喜欢交朋友或照顾大家，这个职业最适合不过了。", "JT_Sage"),
	ProfessionInfo.new(12, "见习巫师", "将魔力注入到自己的体内，使敌人的攻击能量转为回复能量。笑看着敌人精疲力尽的一个一个倒下…巫师难度高实力强，有实力的你快来挑战。", "JT_Wizard"),
	ProfessionInfo.new(13, "见习咒术师", "在战斗中施展各种各样的咒术，使得敌人动弹不得，方寸大乱…想随心所欲的玩弄敌人的你，咒术师是不错的选择。", "JT_Word"),
	ProfessionInfo.new(14, "佣兵", "挥舞著明晃晃的大斧，以终极重力横扫著一群一群的敌人，佣兵是各职业中攻最高的，想体验高战斗能力的你佣兵是你最好的选择！", "JT_Axe"),
	ProfessionInfo.new(15, "剑士", "挥动著手中的圣剑，毫不留情的斩杀所有危害善良的邪恶魔物…剑是武器中的君子，剑士就可谓是战士中的强者，不妨试下，去体验英雄的滋味。", "JT_Sword"),
	ProfessionInfo.new(16, "骑士", "拥有高尚的骑士精神，绝不允许别人伤害自己队友的热血…超高的防御力让骑士成为战斗中最难缠的角色之一。喜欢刀枪不入的你，骑士就是你最佳的选择!", "JT_Knight"),
	ProfessionInfo.new(17, "猎人", "藏匿在隐密的地点，优雅的取出箭矢搭在弓上，精准瞄准著敌人的心脏，手起矢出，敌人应声而倒…难度小，适合刚进大陆的你。", "JT_Archer"),
	ProfessionInfo.new(18, "武僧", "赤手空拳将敌人击败在自己的拳头之上…格斗空手的威力比其它职业的要大。想体验战斗系技能的精髓的你，就尝试这个职业吧。", "JT_Fighter"),
	ProfessionInfo.new(19, "中级刺客", "漂亮的刺杀，通常可以一轮把对方带走，赢得队友羡慕的眼光…喜欢向难度挑战的玩家可以选择刺客这个职业。", "JT_Ninja"),
	ProfessionInfo.new(22, "法师", "吟唱着古老的咒文，释放出强大的精神力，以毁灭性的魔法将眼前的敌人带入死亡的地狱…如果你想体验群攻强大的魔法威力，就选择法师吧。", "JT_Mage"),
	ProfessionInfo.new(23, "牧师", "默念着回复体力的神圣咒文，让身受重伤的队友重新站起来，永远在后面支持着队友…如果你喜欢交朋友或照顾大家，这个职业最适合不过了。", "JT_Sage"),
	ProfessionInfo.new(24, "巫师", "将魔力注入到自己的体内，使敌人的攻击能量转为回复能量。笑看着敌人精疲力尽的一个一个倒下…巫师难度高实力强，有实力的你快来挑战。", "JT_Wizard"),
	ProfessionInfo.new(25, "咒术师", "在战斗中施展各种各样的咒术，使得敌人动弹不得，方寸大乱…想随心所欲的玩弄敌人的你，咒术师是不错的选择。", "JT_Word"),
	ProfessionInfo.new(26, "王宫佣兵", "挥舞著明晃晃的大斧，以终极重力横扫著一群一群的敌人，佣兵是各职业中攻最高的，想体验高战斗能力的你佣兵是你最好的选择！", "JT_Axe"),
	ProfessionInfo.new(27, "王宫剑士", "挥动著手中的圣剑，毫不留情的斩杀所有危害善良的邪恶魔物…剑是武器中的君子，剑士就可谓是战士中的强者，不妨试下，去体验英雄的滋味。", "JT_Sword"),
	ProfessionInfo.new(28, "王宫骑士", "拥有高尚的骑士精神，绝不允许别人伤害自己队友的热血…超高的防御力让骑士成为战斗中最难缠的角色之一。喜欢刀枪不入的你，骑士就是你最佳的选择!", "JT_Knight"),
	ProfessionInfo.new(29, "王宫猎人", "藏匿在隐密的地点，优雅的取出箭矢搭在弓上，精准瞄准著敌人的心脏，手起矢出，敌人应声而倒…难度小，适合刚进大陆的你。", "JT_Archer"),
	ProfessionInfo.new(30, "王宫武僧", "赤手空拳将敌人击败在自己的拳头之上…格斗空手的威力比其它职业的要大。想体验战斗系技能的精髓的你，就尝试这个职业吧。", "JT_Fighter"),
	ProfessionInfo.new(31, "高级刺客", "漂亮的刺杀，通常可以一轮把对方带走，赢得队友羡慕的眼光…喜欢向难度挑战的玩家可以选择刺客这个职业。", "JT_Ninja"),
	ProfessionInfo.new(34, "王宫法师", "吟唱着古老的咒文，释放出强大的精神力，以毁灭性的魔法将眼前的敌人带入死亡的地狱…如果你想体验群攻强大的魔法威力，就选择法师吧。", "JT_Mage"),
	ProfessionInfo.new(35, "王宫牧师", "默念着回复体力的神圣咒文，让身受重伤的队友重新站起来，永远在后面支持着队友…如果你喜欢交朋友或照顾大家，这个职业最适合不过了。", "JT_Sage"),
	ProfessionInfo.new(36, "王宫巫师", "将魔力注入到自己的体内，使敌人的攻击能量转为回复能量。笑看着敌人精疲力尽的一个一个倒下…巫师难度高实力强，有实力的你快来挑战。", "JT_Wizard"),
	ProfessionInfo.new(37, "王宫咒术师", "在战斗中施展各种各样的咒术，使得敌人动弹不得，方寸大乱…想随心所欲的玩弄敌人的你，咒术师是不错的选择。", "JT_Word"),
	ProfessionInfo.new(38, "战斧师范", "挥舞著明晃晃的大斧，以终极重力横扫著一群一群的敌人，佣兵是各职业中攻最高的，想体验高战斗能力的你佣兵是你最好的选择！", "JT_Axe"),
	ProfessionInfo.new(39, "剑士师范", "挥动著手中的圣剑，毫不留情的斩杀所有危害善良的邪恶魔物…剑是武器中的君子，剑士就可谓是战士中的强者，不妨试下，去体验英雄的滋味。", "JT_Sword"),
	ProfessionInfo.new(40, "骑士师范", "拥有高尚的骑士精神，绝不允许别人伤害自己队友的热血…超高的防御力让骑士成为战斗中最难缠的角色之一。喜欢刀枪不入的你，骑士就是你最佳的选择!", "JT_Knight"),
	ProfessionInfo.new(41, "猎人师范", "藏匿在隐密的地点，优雅的取出箭矢搭在弓上，精准瞄准著敌人的心脏，手起矢出，敌人应声而倒…难度小，适合刚进大陆的你。", "JT_Archer"),
	ProfessionInfo.new(42, "武僧师范", "赤手空拳将敌人击败在自己的拳头之上…格斗空手的威力比其它职业的要大。想体验战斗系技能的精髓的你，就尝试这个职业吧。", "JT_Fighter"),
	ProfessionInfo.new(43, "影", "漂亮的刺杀，通常可以一轮把对方带走，赢得队友羡慕的眼光…喜欢向难度挑战的玩家可以选择刺客这个职业。", "JT_Ninja"),
	ProfessionInfo.new(46, "魔导士", "吟唱着古老的咒文，释放出强大的精神力，以毁灭性的魔法将眼前的敌人带入死亡的地狱…如果你想体验群攻强大的魔法威力，就选择法师吧。", "JT_Mage"),
	ProfessionInfo.new(47, "主教", "默念着回复体力的神圣咒文，让身受重伤的队友重新站起来，永远在后面支持着队友…如果你喜欢交朋友或照顾大家，这个职业最适合不过了。", "JT_Sage"),
	ProfessionInfo.new(48, "巫术大师", "将魔力注入到自己的体内，使敌人的攻击能量转为回复能量。笑看着敌人精疲力尽的一个一个倒下…巫师难度高实力强，有实力的你快来挑战。", "JT_Wizard"),
	ProfessionInfo.new(49, "降头师", "在战斗中施展各种各样的咒术，使得敌人动弹不得，方寸大乱…想随心所欲的玩弄敌人的你，咒术师是不错的选择。", "JT_Word"),
]

# 创建角色时可选的职业（用户选择：剑士、法师、牧师、刺客、猎人）
var _starter_professions: Array[ProfessionInfo] = [
	ProfessionInfo.new(3, "见习剑士", "挥动著手中的圣剑，毫不留情的斩杀所有危害善良的邪恶魔物…剑是武器中的君子，剑士就可谓是战士中的强者，不妨试下，去体验英雄的滋味。", "JT_Sword"),
	ProfessionInfo.new(10, "见习法师", "吟唱着古老的咒文，释放出强大的精神力，以毁灭性的魔法将眼前的敌人带入死亡的地狱…如果你想体验群攻强大的魔法威力，就选择法师吧。", "JT_Mage"),
	ProfessionInfo.new(11, "见习牧师", "默念着回复体力的神圣咒文，让身受重伤的队友重新站起来，永远在后面支持着队友…如果你喜欢交朋友或照顾大家，这个职业最适合不过了。", "JT_Sage"),
	ProfessionInfo.new(7, "初级刺客", "漂亮的刺杀，通常可以一轮把对方带走，赢得队友羡慕的眼光…喜欢向难度挑战的玩家可以选择刺客这个职业。", "JT_Ninja"),
	ProfessionInfo.new(5, "见习猎人", "藏匿在隐密的地点，优雅的取出箭矢搭在弓上，精准瞄准著敌人的心脏，手起矢出，敌人应声而倒…难度小，适合刚进大陆的你。", "JT_Archer"),
]

# 获取所有职业
func get_all_professions() -> Array[ProfessionInfo]:
	return _all_professions

# 获取创建角色时可选的初级职业
func get_starter_professions() -> Array[ProfessionInfo]:
	return _starter_professions

# 根据ID获取职业信息
func get_profession_by_id(id: int) -> ProfessionInfo:
	for prof in _all_professions:
		if prof.id == id:
			return prof
	return null

# 根据JobType获取职业列表
func get_professions_by_type(job_type: String) -> Array[ProfessionInfo]:
	var result: Array[ProfessionInfo] = []
	for prof in _all_professions:
		if prof.job_type == job_type:
			result.append(prof)
	return result
