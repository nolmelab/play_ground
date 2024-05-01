# Vcpkg 

https://vcpkg.io/en/


## Get started

https://learn.microsoft.com/ko-kr/vcpkg/get_started/get-started?pivots=shell-cmd

- As several blogs on vcpkg instructs, cloned into /opt/vcpkg and boostrapped.
- vcpkg integrate install 
  - CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake"
- ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg : creates a symbolic link

### CMake Project Tree

- .vscode/settings.json 
  - set "cmake.sourceDirectory" to the root of the project, where CMakeLists.txt for the project exists.
- add CMakeLists.txt to each folder to make a cmake tree.

### vcpkg setting

Check with following very simple CMakeLists.txt:
```c
cmake_minimum_required(VERSION 3.22)
project("Sample")

set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-linux")
include(${CMAKE_TOOLCHAIN_FILE})

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(Sample PRIVATE spdlog::spdlog)

add_executable(Sample Main.cpp)
```


vscode settings does not work. For now, following commands will be used instead:
- set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
- set(VCPKG_TARGET_TRIPLET "x64-linux")
- include(${CMAKE_TOOLCHAIN_FILE})

Error: 
> Cannot specify link libraries for target "Sample" which is not built by this project

target_link_libraries must follow add_executable() since it requires the target!

### vscode setting

To make vscode work as IDE using cmake, there are required setups:
- configure settings.json for user 
    "cmake.configureSettings": {
       "CMAKE_TOOLCHAIN_FILE" : "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" 
    },
- restart vscode 
  - then it works without manually including vcpkg.cmake file


## Build & Run 

vscode command palette has :
- CMake: Configure
- CMake: Build
- CMake: Run wihtout Debugging
  - Shows a list of executable targets automagically

Great! 

