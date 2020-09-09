cmake_minimum_required(VERSION 3.17)

project(
  CppLox
  VERSION 1.0.0
  DESCRIPTION "Going through CraftingInterpreters C part but implementing it in C++."
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(cmake/StandardProjectSettings.cmake)

# Link this "library" to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Dependencies
add_subdirectory(vendor/fmt)

# Application libraries and files
add_subdirectory(cpplox)
