#include <stdio.h>
#include "lib/interpreter.h"

const size_t stack_size = 20;

const union instruction program[] = {
        {.as_arg64 = {ST_PUSH, 10}},
        {ST_DUP},
        {ST_POP},
        {ST_IREAD},
        {ST_SWAP},
        {ST_IMUL},
        {ST_IPRINT},
        {ST_STOP},
};

int main() {
    struct interpreter_state state = state_create(program, stack_size);
    interpret(&state);
    state_destroy(&state);
    return 0;
}
