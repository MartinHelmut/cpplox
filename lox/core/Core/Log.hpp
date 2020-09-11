#pragma once

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace Lox {

class Log {
 private:
  static std::shared_ptr<spdlog::logger> s_Logger;

 public:
  static void Init();

  static std::shared_ptr<spdlog::logger>& GetLogger() {
    return s_Logger;
  }
};

}  // namespace Lox

// Lox logging

#define LOX_TRACE(...) ::Lox::Log::GetLogger()->trace(__VA_ARGS__)
#define LOX_INFO(...) ::Lox::Log::GetLogger()->info(__VA_ARGS__)
#define LOX_WARN(...) ::Lox::Log::GetLogger()->warn(__VA_ARGS__)
#define LOX_ERROR(...) ::Lox::Log::GetLogger()->error(__VA_ARGS__)
#define LOX_FATAL(...) ::Lox::Log::GetLogger()->fatal(__VA_ARGS__)
