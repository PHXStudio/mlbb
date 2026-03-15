#ifndef MY_REGISTER_TYPES_H
#define MY_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

// 初始化模块的函数
void initialize_my_module(ModuleInitializationLevel p_level);

// 卸载模块的函数
void uninitialize_my_module(ModuleInitializationLevel p_level);

#endif // MY_REGISTER_TYPES_H