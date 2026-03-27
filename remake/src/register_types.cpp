#include "register_types.h"

#include "gdexample.h"
#include "net/ServerAgent.h"
#include "net/ServerProxy.h"
#include "net/ServerStub.h"
#include "net/NetConn.h"


#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>


#include "rpc_gen/proto_godot.h"
#include "rpc_gen/global_godot.h"

#include "rpc_gen/proto_godot_reg.h"
#include "rpc_gen/global_godot_reg.h"

using namespace godot;

void initialize_my_module(ModuleInitializationLevel p_level) {
  // GDExtension 有多个初始化级别（Core, Servers, Scene, Editor）
  // 通常我们把自定义节点注册在 SCENE 级别
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

#define GDREGISTER_CLASS(m_class) ClassDB::register_class<m_class>()
  REGISTER_global_CLASSES;
  REGISTER_proto_CLASSES;
#undef GDREGISTER_CLASS

  ClassDB::register_class<GDExample>();
  ClassDB::register_class<ServerAgent>();
  ClassDB::register_class<ServerProxy>();
  ClassDB::register_class<ServerStub>();

  ClassDB::register_class<NetConn>();


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