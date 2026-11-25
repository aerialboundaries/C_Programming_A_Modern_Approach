cmake_minimum_required(VERSION 3.20)
project(calc LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(calc
  calc.c
  stack.c
  token.c
  operate.c
)

target_compile_options(calc PRIVATE
  -Wall
  -Wextra
  -std=c99
  -pedantic
)
