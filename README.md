# CppLox

Going through CraftingInterpreters C part but implementing it in C++. **Note:** This code is written on a Mac and not tested on other systems. Therefore tooling is used out of this perspective as well.

## Contents

* [Required tools](#required-tools)
* [Build](#build)
* [Run](#run)
* [License addition](#license-addition)

## Required tools

### cmake

* Site: https://cmake.org/
* Github: https://github.com/Kitware/CMake

Install on Mac (if not already present):

```shell script
brew install cmake
```

### LLVM

* Site: https://llvm.org/
* Github: https://github.com/llvm/llvm-project

Tools from the LLVM toolchain are used. To install LLVM on Mac run:

```shell script
brew install llvm
```

Tools used from the toolset:

* clang-tidy
* clang-format

To link these tools run:

```shell script
ln -s "$(brew --prefix llvm)/bin/clang-format" "/usr/local/bin/clang-format"
ln -s "$(brew --prefix llvm)/bin/clang-tidy" "/usr/local/bin/clang-tidy"
```

### Ninja

* Site: https://ninja-build.org/
* Github: https://github.com/ninja-build/ninja

You can install Ninja on Mac via brew:

```shell script
brew install ninja
```

## Build

### Debug

Build the configuration files with cmake:

```shell script
cmake -GNinja -DDEBUG=1 -DCMAKE_BUILD_TYPE=Debug --build build/debug
```

Build the application with Ninja:

```shell script
ninja -C build/debug
```

### Release

Build the configuration files with cmake:

```shell script
cmake -GNinja -DDEBUG=0 -DCMAKE_BUILD_TYPE=Release --build build/release
```

Build the application with Ninja:

```shell script
ninja -C build/release
```

## Run

Run the application either in debug or release mode:

```shell script
# Debug
./build/debug/cpplox/CppLox

# Debug
./build/release/cpplox/CppLox
```

## License addition

Just to be sure, here a reference to the license model of crafting interpreters:
https://github.com/munificent/craftinginterpreters/blob/master/LICENSE
