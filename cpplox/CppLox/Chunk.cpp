#include "Chunk.hpp"

#include <utility>

#include "CppLox/Debug/Instrumentor.hpp"

namespace Lox {

Chunk::Chunk(std::vector<Byte> data) : m_ByteCode(std::move(data)) {
}

void Chunk::Write(OpCode byte, size_t line) {
  Write(static_cast<std::byte>(byte), line);
}

void Chunk::Write(Byte byte, size_t line) {
  LOX_PROFILE_FUNCTION();

  m_ByteCode.push_back(byte);
  m_Lines.push_back(line);
}

void Chunk::Free() {
  LOX_PROFILE_FUNCTION();

  // Workaround to not only ::clear elements but free memory by reducing the capacity:
  std::vector<Byte>().swap(m_ByteCode);
  std::vector<Value>().swap(m_Constants);
  std::vector<size_t>().swap(m_Lines);
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

size_t Chunk::GetPosition(size_t index) const {
  LOX_PROFILE_FUNCTION();

  return m_Lines[index];
}

}  // namespace Lox
