set(NAME "Tests")

enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

# Test runner

add_library(TestRunner OBJECT Tests/Runner.cpp)
target_compile_features(TestRunner PRIVATE cxx_std_17)
target_link_libraries(TestRunner PUBLIC doctest)

# Base test setup

add_library(TestBase INTERFACE)
target_compile_features(TestBase INTERFACE cxx_std_17)
target_include_directories(TestBase INTERFACE ${CMAKE_SOURCE_DIR}/lox/core)
target_link_libraries(TestBase INTERFACE doctest Core)

# Test cases

add_executable(RLEBufferTest Tests/Core/RLEBuffer.unit.cpp $<TARGET_OBJECTS:TestRunner>)
add_test(NAME RLEBufferTest COMMAND RLEBufferTest)
target_link_libraries(RLEBufferTest PRIVATE TestBase)
