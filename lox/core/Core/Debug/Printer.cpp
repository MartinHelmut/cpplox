#include "Printer.hpp"

#include <fmt/format.h>

namespace Lox::Printer {

/** @private */
static size_t SimpleInstruction(const std::string& name, size_t offset) {
  fmt::print("{}\n", name);
  return offset + 1;
}

/** @private */
static size_t ConstantInstruction(const std::string& name, const Ref<Chunk>& chunk, size_t offset) {
  const Byte index{chunk->Read(offset)};
  const Value constant{chunk->ReadConstant(index)};

  fmt::print("{:<16} {:4d} '{}'\n", name, index, constant);
  return offset + 1;
}

size_t DisassembleInstruction(const Ref<Chunk>& chunk, size_t offset) {
  fmt::print("{:04d} ", offset);
  if (offset > 0 && chunk->GetPosition(offset) == chunk->GetPosition(offset - 1)) {
    fmt::print("   | ");
  } else {
    fmt::print("{:4d} ", chunk->GetPosition(offset));
  }

  auto instruction = static_cast<OpCode>(chunk->Read(offset++));

  switch (instruction) {
    case OpCode::CONSTANT:
      return ConstantInstruction("CONSTANT", chunk, offset);
    case OpCode::ADD:
      return SimpleInstruction("ADD", offset);
    case OpCode::SUBTRACT:
      return SimpleInstruction("SUBTRACT", offset);
    case OpCode::MULTIPLY:
      return SimpleInstruction("MULTIPLY", offset);
    case OpCode::DIVIDE:
      return SimpleInstruction("DIVIDE", offset);
    case OpCode::NEGATE:
      return SimpleInstruction("NEGATE", offset);
    case OpCode::RETURN:
      return SimpleInstruction("RETURN", offset);
    default:
      fmt::print("Unknown OpCode {:d}\n", instruction);
      return offset + 1;
  }
}

void DisassembleStack(const Stack<Value>& stack) {
  fmt::print("          ");
  for (const Value& item : stack.GetRaw()) {
    fmt::print("[ {} ]", item);
  }
  fmt::print("\n");
}

void Disassemble(const Ref<Chunk>& chunk, const std::string& name) {
  fmt::print("=== {} ===\n", name);

  size_t offset{0};

  while (offset < chunk->Count()) {
    offset = DisassembleInstruction(chunk, offset);
  }
}

}  // namespace Lox::Printer
