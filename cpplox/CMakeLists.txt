set(CMAKE_CXX_STANDARD 17)
set(NAME "CppLox")

include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

# Inject debugging statement into code
if (DEBUG)
  add_definitions(-DDEBUG=${DEBUG} -DLOX_ENABLE_ASSERTS=${DEBUG})
endif()

if(APPLE)
  add_definitions(-DLOX_PLATFORM_MACOS=1)
endif()

add_executable(${NAME} CppLox/Lox.cpp CppLox/Chunk.cpp CppLox/Chunk.hpp CppLox/Base.hpp)

target_include_directories(${NAME} PRIVATE ./)
target_link_libraries(${NAME} PRIVATE project_warnings fmt)
