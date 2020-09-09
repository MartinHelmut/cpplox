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
  void Disassemble(const std::string& name) const;

 private:
  static void disassembleInstruction(OpCode instruction, size_t offset);

 private:
  std::vector<OpCode> m_ByteCode{};
};

}  // namespace Lox
