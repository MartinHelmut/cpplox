#pragma once

#include <memory>

#if LOX_ENABLE_ASSERTS == 1
#include <csignal>
#include "Core/Log.hpp"
#define LOX_ASSERT(x, ...)                             \
  {                                                   \
    if (!(x)) {                                       \
      LOX_ERROR("Assertion failed: {0}", __VA_ARGS__); \
      raise(SIGTRAP);                                 \
    }                                                 \
  }
#else
#define LOX_ASSERT(x, ...)
#endif

namespace Lox {

template <typename T>
using Scope = std::unique_ptr<T>;

template <typename T, typename... Args>
constexpr Scope<T> CreateScope(Args&&... args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T>
using Ref = std::shared_ptr<T>;

template <typename T, typename... Args>
constexpr Ref<T> CreateRef(Args&&... args) {
  return std::make_shared<T>(std::forward<Args>(args)...);
}

}  // namespace Lox
