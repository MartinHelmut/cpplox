#include "Chunk.hpp"

#include <utility>

#include <fmt/core.h>

namespace Lox {

Chunk::Chunk(std::vector<OpCode> data) : m_ByteCode(std::move(data)) {
}

void Chunk::Write(OpCode byte) {
  m_ByteCode.push_back(byte);
}

void Chunk::Disassemble(const std::string& name) const {
  fmt::print("== {} ==\n", name);

  size_t offset{0};
  for (OpCode instruction : m_ByteCode) {
    disassembleInstruction(instruction, offset++);
  }
}

void Chunk::disassembleInstruction(OpCode instruction, size_t offset) {
  fmt::print("{:04d} ", offset);

  switch (instruction) {
    case OpCode::RETURN:
      fmt::print("RETURN\n");
      break;
    default:
      fmt::print("Unknown OpCode {:d}\n", instruction);
  }
}

}  // namespace Lox
