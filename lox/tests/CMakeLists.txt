set(CMAKE_CXX_STANDARD 17)
set(NAME "Tests")

include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_executable(${NAME} Tests/Runner.cpp
  Tests/Core/RLEBuffer.unit.cpp)

target_compile_features(${NAME} PRIVATE cxx_std_17)

target_include_directories(${NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/lox/tests
  ${CMAKE_SOURCE_DIR}/lox/core)

target_link_libraries(${NAME} PRIVATE doctest Core)
