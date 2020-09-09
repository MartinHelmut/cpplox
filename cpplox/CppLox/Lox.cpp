#include <cstdlib>

#include "CppLox/Base.hpp"
#include "CppLox/Chunk.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {
  Lox::Scope<Lox::Chunk> chunk{Lox::CreateScope<Lox::Chunk>()};

  chunk->Write(Lox::OpCode::RETURN);
  chunk->Disassemble("test chunk");

  return EXIT_SUCCESS;
}
