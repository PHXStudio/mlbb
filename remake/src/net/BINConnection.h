#ifndef __GODOT_BIN_CONNECTION_H__
#define __GODOT_BIN_CONNECTION_H__

#include "ProtocolBufferReader.h"
#include "ProtocolWriter.h"
#include <functional>
#include <godot_cpp/variant/packed_byte_array.hpp>

namespace godot {

/**
 * 基于 PackedByteArray 的 Godot 协议连接适配类。
 * 移除了对 ACE 的依赖，使用 Godot 的原生数据类型。
 */
template <class BIN_STUB, class BIN_PROXY>
class BINConnection : public ProtocolWriter, public BIN_STUB {
public:
  typedef uint16_t HdrType;

  BINConnection() {}

  /**
   * 处理接收到的原始字节数组。
   * 在 Godot 中通常由网络层（如 ENet/Websocket）收到 PackedByteArray 后调用。
   */
  virtual int handleReceived(const PackedByteArray &data) {
    if (proxy_.is_null())
      return 0;

    int processed = 0;
    const uint8_t *d = data.ptr();
    size_t size = (size_t)data.size();
    size_t dLeft = size;

    while (true) {
      if (sizeof(HdrType) > dLeft)
        return processed;
      HdrType dLen = *((HdrType *)d);

      size_t dTLen = sizeof(HdrType) + dLen;
      if (dTLen > dLeft)
        return processed;

      // 使用 PackedByteArray 的切片构造 Reader
      PackedByteArray slice =
          data.slice(processed + sizeof(HdrType), processed + dTLen);
      ProtocolBufferReader r(slice);
      if (!proxy_->dispatch(&r))
        return -1;

      d += dTLen;
      dLeft -= dTLen;
      processed += dTLen;
    }
    return processed;
  }

  /** ProtocolWriter implementation: 写入数据到临时发送缓存 */
  virtual void write(const void *data, size_t len) override {
    const uint8_t *ptr = static_cast<const uint8_t *>(data);
    for (size_t i = 0; i < len; ++i) {
      send_buffer.append(ptr[i]);
    }
  }

  /** Stub events. */
  virtual ProtocolWriter *methodBegin() {
    send_buffer.clear();
    // 预留头部空间
    HdrType tempHdr = 0;
    write(&tempHdr, sizeof(HdrType));
    return this;
  }

  virtual void methodEnd() {
    // 回填内容长度
    HdrType dLen = (HdrType)(send_buffer.size() - sizeof(HdrType));
    uint8_t *ptr = send_buffer.ptrw();
    memcpy(ptr, &dLen, sizeof(HdrType));

    // 触发发送回调（派生类需实现此函数将数据发往网络）
    on_data_ready(send_buffer);
    send_buffer.clear();
  }

  /** 获取待发送数据后的回调接口 */
  virtual void on_data_ready(const PackedByteArray &p_data) = 0;

protected:
  godot::Ref<BIN_PROXY> proxy_;
  PackedByteArray send_buffer;
};

} // namespace godot

#endif
