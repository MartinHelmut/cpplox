#include "Chunk.hpp"

#include <utility>

namespace Lox {

Chunk::Chunk(std::vector<OpCode> data) : m_ByteCode(std::move(data)) {
}

void Chunk::Write(OpCode byte) {
  m_ByteCode.push_back(byte);
}

void Chunk::Disassemble(const std::string& name) const {
  printf("== %s ==\n", name.c_str());

  size_t offset{0};
  for (OpCode instruction : m_ByteCode) {
    disassembleInstruction(instruction, offset++);
  }
}

void Chunk::disassembleInstruction(OpCode instruction, size_t offset) {
  printf("%04zu ", offset);

  switch (instruction) {
    case OpCode::RETURN:
      printf("RETURN\n");
      break;
    default:
      printf("Unknown opcode %hhu\n", instruction);
  }
}

}  // namespace Lox
