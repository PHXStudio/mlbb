#include "register_types.h"

#include "gdexample.h" // 引入你的自定义类

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_my_module(ModuleInitializationLevel p_level) {
  // GDExtension 有多个初始化级别（Core, Servers, Scene, Editor）
  // 通常我们把自定义节点注册在 SCENE 级别
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

  // 注册你的类，这样它才会出现在 Godot 的节点列表中
  GDREGISTER_CLASS(GDExample);
}

void uninitialize_my_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
}

extern "C" {
// 这里的函数名必须与 .gdextension 文件中的 entry_symbol 一致
GDExtensionBool GDE_EXPORT
example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                     const GDExtensionClassLibraryPtr p_library,
                     GDExtensionInitialization *r_initialization) {
  godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
                                                 r_initialization);

  init_obj.register_initializer(initialize_my_module);
  init_obj.register_terminator(uninitialize_my_module);
  init_obj.set_minimum_library_initialization_level(
      MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_obj.init();
}
}