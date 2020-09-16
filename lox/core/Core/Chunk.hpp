#pragma once

#include <string>
#include <vector>

#include "Core/Base.hpp"
#include "Core/RLEBuffer.hpp"

namespace Lox {

using Value = double;
using Byte = std::byte;

enum class OpCode : unsigned char {
  CONSTANT,
  RETURN,
};

class Chunk {
 public:
  Chunk() = default;
  explicit Chunk(std::vector<Byte> data);

  void Write(OpCode byte, int line);
  void Write(Byte byte, int line);
  [[nodiscard]] Byte Read(size_t offset) const;

  [[nodiscard]] size_t Count() const;
  [[nodiscard]] size_t Size() const;

  Byte WriteConstant(Value value);
  [[nodiscard]] Value ReadConstant(Byte index) const;

  [[nodiscard]] int GetPosition(size_t index) const;

 private:
  std::vector<Byte> m_ByteCode{};
  std::vector<Value> m_Constants{};
  RLEBuffer<int> m_Lines{};
};

}  // namespace Lox
