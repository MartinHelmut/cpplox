#pragma once

#include <vector>

namespace Lox {

template <typename T>
struct Element {
  T Value;
  int Length;

  Element(T value, int length) : Value(value), Length(length) {
  }
};

/**
 * Run-length encoding buffer.
 *
 * Disclaimer: Due to "struct padding" the best memory size is achieved by using `int` or smaller.
 */
template <typename T>
class RLEBuffer {
 public:
  RLEBuffer() = default;

  RLEBuffer(std::initializer_list<T> list) {
    for (T item : list) {
      Write(item);
    }
  }

  void Write(const T& value) {
    // Nothing added, add new
    if (m_Data.empty()) {
      m_Data.emplace_back(value, 1);
      return;
    }

    // Last element is different, add new
    size_t lastIndex{m_Data.size() - 1};
    // Not using operator!= here to reduce needed operator count for passed types
    // NOLINTNEXTLINE
    if (!(m_Data[lastIndex].Value == value)) {
      m_Data.emplace_back(value, 1);
      return;
    }

    // Last element is the same, increase repeat count
    m_Data[lastIndex].Length++;
  }

  T Read(size_t index) const {
    int position{0};
    for (Element ele : m_Data) {
      for (int i{0}; i < ele.Length; i++) {
        if (position + i == static_cast<int>(index)) {
          return ele.Value;
        }
      }

      position += ele.Length;
    }

    LOX_ASSERT(false, "RLEBuffer::Read() index out of bounds");
    return m_Data.back().Value;
  }

  void Free() {
    std::vector<Element<T>>().swap(m_Data);
  }

  [[nodiscard]] size_t Count() const {
    size_t count{0};
    for (Element ele : m_Data) {
      count += ele.Length;
    }

    return count;
  }

  [[nodiscard]] size_t Size() const {
    return (m_Data.size() * sizeof(struct Element<T>));
  }

 private:
  std::vector<Element<T>> m_Data{};
};

}  // namespace Lox
