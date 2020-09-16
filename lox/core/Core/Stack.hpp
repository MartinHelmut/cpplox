#pragma once

#include <vector>

namespace Lox {

template <typename T>
class Stack {
 public:
  Stack() = default;

  void Push(const T& value) {
    m_Stack.push_back(value);
  }

  T Pop() {
    T value{m_Stack.back()};
    m_Stack.pop_back();
    return value;
  }

  [[nodiscard]] std::vector<T> GetRaw() const { return m_Stack; }

 private:
  std::vector<T> m_Stack{};
};

}  // namespace Lox
