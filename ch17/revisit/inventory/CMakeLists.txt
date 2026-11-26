cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
project(inventory)
add_executable(inventory)
target_sources(inventory
  PRIVATE
  ./src/inventory2.c
  ./src/readline.c
)

target_compile_options(inventory
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -std=c99
)
