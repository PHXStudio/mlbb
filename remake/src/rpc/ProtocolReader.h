#ifndef __GODOT_PROTOCOL_READER_H__
#define __GODOT_PROTOCOL_READER_H__

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/defs.hpp>
#include <stdint.h>
#include <string>
#include <string.h>

namespace godot {

/** Godot适配的ProtocolReader接口 */
class ProtocolReader {
public:
  virtual bool read(void *data, size_t len) = 0;

  bool readType(int64_t &v) { return read(&v, sizeof(int64_t)); }
  bool readType(uint64_t &v) { return read(&v, sizeof(uint64_t)); }
  bool readType(double &v) { return read(&v, sizeof(double)); }
  bool readType(float &v) { return read(&v, sizeof(float)); }
  bool readType(int32_t &v) { return read(&v, sizeof(int32_t)); }
  bool readType(uint32_t &v) { return read(&v, sizeof(uint32_t)); }
  bool readType(int16_t &v) { return read(&v, sizeof(int16_t)); }
  bool readType(uint16_t &v) { return read(&v, sizeof(uint16_t)); }
  bool readType(int8_t &v) { return read(&v, sizeof(int8_t)); }
  bool readType(uint8_t &v) { return read(&v, sizeof(uint8_t)); }
  bool readType(bool &v) {
    char vv;
    if (!read(&vv, sizeof(char)))
      return false;
    v = vv ? true : false;
    return true;
  }

  bool readType(String &v, uint32_t maxlen = 2048) {
    uint32_t len;
    if (!readDynSize(len) || len > maxlen)
      return false;
    std::string temp;
    temp.resize(len);
    if (!read((void *)temp.c_str(), len))
      return false;
    v = temp.c_str();
    return true;
  }

  bool readDynSize(uint32_t &s) {
    s = 0;
    uint8_t b;
    if (!readType(b))
      return false;
    int32_t n = (b & 0XC0) >> 6;
    s = (b & 0X3F);
    for (int32_t i = 0; i < n; i++) {
      if (!readType(b))
        return false;
      s = (s << 8) | b;
    }
    return true;
  }
};

} // namespace godot

#endif // __GODOT_PROTOCOL_READER_H__