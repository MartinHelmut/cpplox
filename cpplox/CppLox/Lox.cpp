#include <cstdlib>

#include "CppLox/Base.hpp"
#include "CppLox/Chunk.hpp"
#include "CppLox/Printer.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {
  auto chunk{Lox::CreateRef<Lox::Chunk>()};
  auto printer{Lox::CreateScope<Lox::Printer>(chunk)};

  Lox::Byte constant{chunk->AddConstant(1.2)};
  chunk->Write(Lox::OpCode::CONSTANT, 123);
  chunk->Write(constant, 123);

  chunk->Write(Lox::OpCode::RETURN, 123);

  printer->Disassemble("test chunk");

  chunk->Free();

  return EXIT_SUCCESS;
}
