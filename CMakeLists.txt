cmake_minimum_required(VERSION 3.10...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(ultra_test VERSION 0.1.0)
project(ultra_test VERSION 0.1.0
                  DESCRIPTION "Publish allowedd test assignments for job applications"
                  LANGUAGES CXX)

find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable"
    )
if(NOT CLANG_TIDY_EXE)
    message(STATUS "clang-tidy not found.")
else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-header-filter=." "-checks=*, -llvm-header-guard, -fuchsia-*, -cert-*, -modernize-use-trailing-return-type, -hicpp-signed-bitwise")
endif()

add_subdirectory(apps)
add_subdirectory(src)
