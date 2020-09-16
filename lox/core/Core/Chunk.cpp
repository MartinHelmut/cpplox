#include "Chunk.hpp"

#include <utility>

#include "Core/Debug/Instrumentor.hpp"

namespace Lox {

Chunk::Chunk(std::vector<Byte> data) : m_ByteCode(std::move(data)) {
}

void Chunk::Write(OpCode byte, int line) {
  Write(static_cast<std::byte>(byte), line);
}

void Chunk::Write(Byte byte, int line) {
  LOX_PROFILE_FUNCTION();

  m_ByteCode.push_back(byte);
  m_Lines.Write(line);
}

[[nodiscard]] Byte Chunk::Read(size_t offset) const {
  LOX_PROFILE_FUNCTION();

  return m_ByteCode[offset];
};

[[nodiscard]] size_t Chunk::Count() const {
  LOX_PROFILE_FUNCTION();

  return m_ByteCode.size();
}

[[nodiscard]] size_t Chunk::Size() const {
  LOX_PROFILE_FUNCTION();

  return sizeof(OpCode) * m_ByteCode.size();
}

Byte Chunk::AddConstant(Value value) {
  LOX_PROFILE_FUNCTION();

  m_Constants.push_back(value);
  return static_cast<Byte>(m_Constants.size() - 1);
}

[[nodiscard]] Value Chunk::GetConstant(Byte index) const {
  LOX_PROFILE_FUNCTION();

  return m_Constants[static_cast<unsigned long>(index)];
}

int Chunk::GetPosition(size_t index) const {
  LOX_PROFILE_FUNCTION();

  return m_Lines.Read(index);
}

}  // namespace Lox
