#pragma once

#include <vector>
#include <string>

#include "CppLox/Base.hpp"

namespace Lox {

enum class OpCode : unsigned char {
  RETURN,
};

class Chunk {
 public:
  Chunk() = default;
  explicit Chunk(std::vector<OpCode> data);

  void Write(OpCode byte);
  void Free();

  [[nodiscard]] size_t Count() const { return m_ByteCode.size(); }
  [[nodiscard]] size_t Size() const { return sizeof(OpCode) * m_ByteCode.size(); }

  void Disassemble(const std::string& name) const;

 private:
  static void disassembleInstruction(OpCode instruction, size_t offset);

 private:
  std::vector<OpCode> m_ByteCode{};
};

}  // namespace Lox
