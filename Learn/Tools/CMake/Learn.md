# Learn CMake

https://cmake.org/cmake/help/latest/guide/tutorial/index.html

The above link has a step by step tutorial of cmake. 

## Goal

- What are the core concepts in cmake?
- How can it be used in vscode?
- How to practice cmake to use it fluently?
- How to use vcpkg with cmake?

## Core concepts 

CMake works with variables and actions:
- set variables to configure the project
- call commands to perform actions on the project

## Tutorial

### Step 1 - Basic Starting Point

https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html

TIPS:
- search commands and examples. there are many.
- read CMakeLists.txt files of other established projects

Learned:
- cmake_minimum_required()
- project()
- add_executable(target source)


### Step 2 - Adding a Library

https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20a%20Library.html

To organize a project, we need to split it into several subprojects. 
Subprojects need to be libraries to be reused in other projects. 
Hence, we need to know how to cofigure cmake for libraries. 

For example, the project play would have following subprojects as libraries
    - ground
    - db
    - data
    - link
    - core

and each subproject and test project to build and run tests on each library.

- add_subdirectory()
- target_include_directories(target dir...)
- target_link_libraries(target PUBLIC lib...)

### https://www.youtube.com/watch?v=A735Y4kMIPM

- add_library(target INTERFACE)
    - header only libraries
- target_compile_definitions()
    - adding macros

visual studio supports cmake projects. Try it.

### Step 3 - Adding usage requirements for a library

- ${PROJECT_BINARY_DIR}
- list(APPEND VAR value...)

- cmake variables and types:
    - string and list of strings 
    - normal and cache 

It seems that the string is casted to the target type when required freely
, but depending on the context of the type casting.

Some other functions like option set the variable to ON or OFF. 
But we can also interpret this as type conversion from "ON" or "OFF" to 
boolean depending on the context like in if (USE_OPTION).


Anatomy:
- The level of detail is the first one to decide
    - implementation level is not required for tools
    - usage level is the required level of detail for most tools and libraries
    - concept level is a little deeper than usage level

Usage level anatomy is required to master a tool, but some core cocepts 
are essential. 


### Step 4 - Adding generator expressions

What is a generator expressions?

https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7)

- generator expressions are expressions. So they are evaluated to values. 
- generator expressions are evaluated during build system generation for specific build configuration
- target_include_directories(tgt PRIVATE /opt/include/$<CXX_COMPILER_ID>)

Since generator expressions are expressions, there are a few operators on them also.
This makes the expressions powerful, but it also introduces some complexity. 

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)

What is the value of msvc_cxx if COMPILE_LANG_AND_ID is Clang?
- It is just the string provided
- It is evaluated in target_compile_options() command when provided with $<> expression
- Hence it is evaluated in the command context.

$<v1, v2> evaluates to 0 or 1 boolean.
$<boolean: v> evaluaes to v when it is true else empty string.

The above interpretation works for the above example and it is a simplest $<condition:true_string> form.

### Summary

I will not follow the official tutorial further since it is more exercise form rather than 
providing information. There are lots more exercises to do with vcpkg. 

















