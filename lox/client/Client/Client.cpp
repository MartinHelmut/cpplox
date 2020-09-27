#include <cstdlib>

#include <Core.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {
  LOX_PROFILE_BEGIN_SESSION_WITH_FILE("LoxLang", "lox-profile.json");

  Lox::Log::Init();

  {
    LOX_PROFILE_SCOPE("TestChunk");
    const auto vm{Lox::CreateScope<Lox::VirtualMachine>()};
    const auto chunk{Lox::CreateRef<Lox::Chunk>()};

    Lox::Byte constant{chunk->WriteConstant(1.2)};
    chunk->Write(Lox::OpCode::CONSTANT, 1);
    chunk->Write(constant, 1);

    Lox::Byte constant2{chunk->WriteConstant(3.4)};
    chunk->Write(Lox::OpCode::CONSTANT, 1);
    chunk->Write(constant2, 1);

    chunk->Write(Lox::OpCode::ADD, 1);

    Lox::Byte constant3{chunk->WriteConstant(5.6)};
    chunk->Write(Lox::OpCode::CONSTANT, 1);
    chunk->Write(constant3, 1);

    chunk->Write(Lox::OpCode::DIVIDE, 1);
    chunk->Write(Lox::OpCode::NEGATE, 1);

    chunk->Write(Lox::OpCode::RETURN, 1);

    vm->Interpret(chunk);
  }

  LOX_PROFILE_END_SESSION();

  return EXIT_SUCCESS;
}
