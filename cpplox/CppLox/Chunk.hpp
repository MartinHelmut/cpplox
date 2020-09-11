#pragma once

#include <string>
#include <vector>

#include "CppLox/Core/Base.hpp"

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

  void Write(OpCode byte, size_t line);
  void Write(Byte byte, size_t line);
  [[nodiscard]] Byte Read(size_t offset) const;

  void Free();
  [[nodiscard]] size_t Count() const;
  [[nodiscard]] size_t Size() const;

  Byte AddConstant(Value value);
  [[nodiscard]] Value GetConstant(Byte index) const;

  [[nodiscard]] size_t GetPosition(size_t index) const;

 private:
  std::vector<Byte> m_ByteCode{};
  std::vector<Value> m_Constants{};
  std::vector<size_t> m_Lines{};
};

}  // namespace Lox
