#include "VirtualMachine.hpp"

#include <fmt/format.h>

#include "Core/Debug/Printer.hpp"

namespace Lox {

InterpretResult VirtualMachine::Interpret(const Ref<Chunk>& chunk) {
  m_Chunk = chunk;
  m_ProgramCounter = 0;

  return Run();
}

InterpretResult VirtualMachine::Run() {
  while (true) {
#if LOX_ENABLE_DISASSEMBLE == 1
    LOX_DISASSEMBLE_STACK(m_Stack);
    LOX_DISASSEMBLE_INSTRUCTION(m_Chunk, m_ProgramCounter);
#endif

    OpCode instruction{m_Chunk->Read(m_ProgramCounter++)};
    switch (instruction) {
      case OpCode::CONSTANT: {
        Value constant{m_Chunk->ReadConstant(m_Chunk->Read(m_ProgramCounter++))};
        m_Stack.Push(constant);
        break;
      }
      case OpCode::RETURN: {
        fmt::print("{}\n", m_Stack.Pop());
        return InterpretResult::OK;
      }
      default: {
        return InterpretResult::RUNTIME_ERROR;
      }
    }
  }
}

}  // namespace Lox
