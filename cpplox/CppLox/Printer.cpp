#include "Printer.hpp"

#include <utility>

#include <fmt/core.h>

namespace Lox {

Printer::Printer(Ref<Chunk> chunk) : m_Chunk(std::move(chunk)) {
}

void Printer::Disassemble(const std::string& name) {
  fmt::print("== {} ==\n", name);

  m_Offset = 0;
  while (m_Offset < m_Chunk->Count()) {
    DisassembleInstruction();
  }
}

void Printer::DisassembleInstruction() {
  fmt::print("{:04d} ", m_Offset);
  if (m_Offset > 0 && m_Chunk->GetPosition(m_Offset) == m_Chunk->GetPosition(m_Offset - 1)) {
    fmt::print("   | ");
  } else {
    fmt::print("{:4d} ", m_Chunk->GetPosition(m_Offset));
  }

  auto instruction = static_cast<OpCode>(m_Chunk->Read(m_Offset++));

  switch (instruction) {
    case OpCode::CONSTANT:
      ConstantInstruction("CONSTANT");
      break;
    case OpCode::RETURN:
      SimpleInstruction("RETURN");
      break;
    default:
      fmt::print("Unknown OpCode {:d}\n", instruction);
  }
}

void Printer::SimpleInstruction(const std::string& name) {
  fmt::print("{}\n", name);
}

void Printer::ConstantInstruction(const std::string& name) {
  Byte index{m_Chunk->Read(m_Offset++)};
  Value constant{m_Chunk->GetConstant(index)};

  fmt::print("{:<16} {:4d} '{}'\n", name, index, constant);
}

}  // namespace Lox
