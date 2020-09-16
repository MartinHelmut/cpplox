#pragma once

#include <string>

#include "Core/Chunk.hpp"
#include "Core/Stack.hpp"

namespace Lox::Printer {

void Disassemble(const Ref<Chunk>& chunk, const std::string& name);
size_t DisassembleInstruction(const Ref<Chunk>& chunk, size_t offset);
void DisassembleStack(const Stack<Value>& stack);

}  // namespace Lox

#define LOX_DISASSEMBLE(chunk, name) ::Lox::Printer::Disassemble(chunk, "test chunk")
#define LOX_DISASSEMBLE_INSTRUCTION(chunk, offset) ::Lox::Printer::DisassembleInstruction(chunk, offset)
#define LOX_DISASSEMBLE_STACK(stack) ::Lox::Printer::DisassembleStack(stack)
