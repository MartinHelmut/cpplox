set(NAME "Client")

include(${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_executable(${NAME} Client/Client.cpp)

target_compile_features(${NAME} PRIVATE cxx_std_17)

target_include_directories(${NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/lox/client
  ${CMAKE_SOURCE_DIR}/lox/core)

target_link_libraries(${NAME} PRIVATE project_warnings Core)
