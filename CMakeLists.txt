cmake_minimum_required(VERSION 3.24)
project(styok C)

set(CMAKE_C_STANDARD 17)

add_executable(styok main.c lib/interpreter.h lib/stack/list.h lib/maybe_int64/maybe_int64.h lib/stack/stack.h lib/maybe_int64/maybe_int64.c lib/stack/list.c lib/stack/stack.c lib/interpreter.c)
