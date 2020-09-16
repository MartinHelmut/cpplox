#pragma once

#include <stack>

#include "Core/Base.hpp"
#include "Core/Chunk.hpp"
#include "Core/Stack.hpp"

namespace Lox {

enum class InterpretResult : unsigned char {
  OK,
  COMPILE_ERROR,
  RUNTIME_ERROR
};

class VirtualMachine {
 public:
  InterpretResult Interpret(const Ref<Chunk>& chunk);

 private:
  InterpretResult Run();

 private:
  Ref<Chunk> m_Chunk;
  // Often called IP for "instruction pointer", as I am using a position into
  // the buffer I use the other term PC ("program counter").
  // It will always point to the *next* instruction to execute.
  size_t m_ProgramCounter{0};
  Stack<Value> m_Stack{};
};

}  // namespace Lox
