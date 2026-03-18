#ifndef __GODOT_ENUM_INFO_H__
#define __GODOT_ENUM_INFO_H__

#include <godot_cpp/variant/string.hpp>
#include <vector>
#include <string>
#include <stdint.h>

namespace godot {

class EnumInfo
{
public:
	EnumInfo(const std::string& name, void (*initFunc)(EnumInfo* einfo)):
	name_(name)
	{
		initFunc(this);
	}

	int getItemId(const std::string& item)
	{
		for(size_t i = 0; i < items_.size(); ++i) {
			if(items_[i] == item) return (int)i;
		}
		return -1;
	}

	const char* getItemName(int item)
	{
		if(item < 0 || item >= (int)items_.size())
			return NULL;
		return items_[item].c_str();
	}

	std::string					name_;
	std::vector<std::string>	items_;
};

#define ENUM(E)	enum##E

} // namespace godot

#endif
