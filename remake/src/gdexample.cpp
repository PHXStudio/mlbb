#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GDExample::_bind_methods() {
  // 1. 注册普通函数
  ClassDB::bind_method(D_METHOD("reset_position"), &GDExample::reset_position);

  // 2. 注册变量（属性）的 Getter 和 Setter 函数
  ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
  ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDExample::set_amplitude);

  // 3. 将前面注册的 Getter/Setter 绑定为一个公开的只读、可写属性 (会在 Godot 编辑器的检查器中出现)
  ClassDB::add_property("GDExample", PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
}

GDExample::GDExample() { 
    time_passed = 0.0; 
    amplitude = 10.0; // 初始化这个变量
}

GDExample::~GDExample() {}

void GDExample::_process(double delta) {
  time_passed += delta;

  Vector2 new_position = Vector2(amplitude + (amplitude * sin(time_passed * 2.0)),
                                 amplitude + (amplitude * cos(time_passed * 2.0)));

  set_position(new_position);
}

// 补充我们上面新增函数的实现代码
void GDExample::set_amplitude(const double p_amplitude) {
  amplitude = p_amplitude;
}

double GDExample::get_amplitude() const {
  return amplitude;
}

void GDExample::reset_position() {
  time_passed = 0.0;
  set_position(Vector2(0, 0));
}