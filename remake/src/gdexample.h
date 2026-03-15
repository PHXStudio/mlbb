#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDExample : public Sprite2D {
  GDCLASS(GDExample, Sprite2D)

private:
  double time_passed;
  double amplitude; // 我们想在 Godot 检查器中暴露的变量

protected:
  static void _bind_methods(); // 必须：用于向 Godot 注册方法

public:
  GDExample();
  ~GDExample();

  void _process(double delta) override; // 重写虚函数

  // 变量(属性)的 Get 和 Set 方法
  void set_amplitude(const double p_amplitude);
  double get_amplitude() const;

  // 自定义函数
  void reset_position();
};

} // namespace godot

#endif