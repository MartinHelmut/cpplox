#include <cstdlib>

#include <Core.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {
  LOX_PROFILE_BEGIN_SESSION_WITH_FILE("LoxLang", "lox-profile.json");

  Lox::Log::Init();

  {
    LOX_PROFILE_SCOPE("TestChunk");
    const auto chunk{Lox::CreateRef<Lox::Chunk>()};

    Lox::Byte constant{chunk->AddConstant(1.2)};
    chunk->Write(Lox::OpCode::CONSTANT, 123);
    chunk->Write(constant, 123);

    chunk->Write(Lox::OpCode::RETURN, 123);

    LOX_PRINTER_DISASSEMBLE(chunk, "TestChunk");
  }

  LOX_PROFILE_END_SESSION();

  return EXIT_SUCCESS;
}
