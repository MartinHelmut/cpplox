#pragma once

#include <string>

#include "Core/Log.hpp"
#include "Core/Base.hpp"
#include "Core/Chunk.hpp"

namespace Lox {

class Printer {
 public:
  void Disassemble(const Ref<Chunk>& chunk, const std::string& name) {
    fmt::print("=== {} ===\n", name);

    m_Chunk = chunk;
    m_Offset = 0;

    while (m_Offset < m_Chunk->Count()) {
      DisassembleInstruction();
    }
  }

 private:
  void DisassembleInstruction() {
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

  static void SimpleInstruction(const std::string& name) {
    fmt::print("{}\n", name);
  }

  void ConstantInstruction(const std::string& name) {
    const Byte index{m_Chunk->Read(m_Offset++)};
    const Value constant{m_Chunk->GetConstant(index)};

    fmt::print("{:<16} {:4d} '{}'\n", name, index, constant);
  }

 private:
  size_t m_Offset{0};
  Ref<Chunk> m_Chunk;
};

}  // namespace Lox

#define LOX_PRINTER_DISASSEMBLE(chunk, name) ::Lox::Printer().Disassemble(chunk, "test chunk")
