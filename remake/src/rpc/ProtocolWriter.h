#ifndef __GODOT_PROTOCOL_WRITER_H__
#define __GODOT_PROTOCOL_WRITER_H__

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <stdint.h>
#include <string>
#include <string.h>

namespace godot {

/** Godot适配的ProtocolWriter接口 */
class ProtocolWriter {
public:
  virtual void write(const void *data, size_t len) = 0;

  void writeType(int64_t v) { write(&v, sizeof(int64_t)); }
  void writeType(uint64_t v) { write(&v, sizeof(uint64_t)); }
  void writeType(double v) { write(&v, sizeof(double)); }
  void writeType(float v) { write(&v, sizeof(float)); }
  void writeType(int32_t v) { write(&v, sizeof(int32_t)); }
  void writeType(uint32_t v) { write(&v, sizeof(uint32_t)); }
  void writeType(int16_t v) { write(&v, sizeof(int16_t)); }
  void writeType(uint16_t v) { write(&v, sizeof(uint16_t)); }
  void writeType(int8_t v) { write(&v, sizeof(int8_t)); }
  void writeType(uint8_t v) { write(&v, sizeof(uint8_t)); }
  void writeType(bool v) {
    char vv = v ? 1 : 0;
    write(&vv, sizeof(char));
  }

  void writeType(const String &v) {
    std::string s = v.utf8().get_data();
    uint32_t len = (uint32_t)s.length();
    UtilityFunctions::print("[ProtocolWriter::writeType] Writing string: '", s.c_str(), "', length: ", len);
    writeDynSize(len);
    write(s.c_str(), len);
  }

  void writeDynSize(uint32_t s) {
    uint8_t *p = (uint8_t *)(&s);
    uint8_t n = 0;
    if (s <= 0X3F)
      n = 0;
    else if (s <= 0X3FFF)
      n = 1;
    else if (s <= 0X3FFFFF)
      n = 2;
    else if (s <= 0X3FFFFFFF)
      n = 3;
    p[n] |= (n << 6);
    for (int32_t i = (int32_t)n; i >= 0; i--)
      writeType(p[i]);
  }
};

} // namespace godot

#endif // __GODOT_PROTOCOL_WRITER_H__