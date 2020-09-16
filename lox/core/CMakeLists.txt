set(CMAKE_CXX_STANDARD 17)
set(NAME "Core")

include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(${NAME} STATIC
  Core.hpp Core/Chunk.cpp Core/Chunk.hpp
  Core/Base.hpp Core/Log.cpp Core/Log.hpp
  Core/Debug/Printer.hpp Core/Debug/Printer.cpp Core/Debug/Instrumentor.hpp
  Core/RLEBuffer.hpp Core/VirtualMachine.cpp Core/VirtualMachine.hpp Core/Stack.hpp)

target_include_directories(${NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lox/core)

target_link_libraries(${NAME}
  PRIVATE project_warnings
  PUBLIC fmt spdlog)
