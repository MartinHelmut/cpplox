#pragma once

#include <string>

#include "CppLox/Base.hpp"
#include "CppLox/Chunk.hpp"

namespace Lox {

class Printer {
 public:
  void Disassemble(const Ref<Chunk>& chunk, const std::string& name);

 private:
  void DisassembleInstruction();
  static void SimpleInstruction(const std::string& name);
  void ConstantInstruction(const std::string& name);

 private:
  size_t m_Offset{0};
  Ref<Chunk> m_Chunk;
};

}  // namespace Lox
