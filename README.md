# CppLox

Going through CraftingInterpreters C part but implementing it in C++. **Note:** This code is written on a Mac and not tested on other systems. Therefore tooling is used out of this perspective as well.

## Contents

* [Required tools](#required-tools)
* [Setup](#setup)
* [Update](#update)
* [Build](#build)
* [Run](#run)
* [Profiling](#profiling)
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

## Setup

Clone the project with all submodules:

```shell script
git clone --recurse-submodules -j8 git@github.com:MartinHelmut/cpplox.git
```

## Update

```shell script
git pull && git submodule update --init
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

After [building the application](#build) you can either run the client in debug or release mode:

```shell script
# Debug
./build/debug/lox/client/Client

# Release
./build/release/lox/client/Client
```

## Profiling

There is a special profiling build running cmake with `PROFILE=1`:

```shell script
# Create config files
cmake -GNinja -DDEBUG=0 -DPROFILE=1 -DCMAKE_BUILD_TYPE=Release --build build/profile
# Build profile runner
ninja -C build/profile
```

Running the profiler executable will generate a `lox-profile.json` file that can be used with any Chromium based browser tracing tool, e.g. [chrome://tracing](chrome://tracing/). Just drag and drop the file into the tracing view. To generate the file run:

```shell script
./build/profile/lox/client/Client
```

## License addition

Just to be sure, here a reference to the license model of crafting interpreters:
https://github.com/munificent/craftinginterpreters/blob/master/LICENSE
