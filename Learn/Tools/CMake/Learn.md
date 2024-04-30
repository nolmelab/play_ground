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







