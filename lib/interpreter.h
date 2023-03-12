#ifndef C_STYOK_H
#define C_STYOK_H

#include <inttypes.h>
#include "stack/stack.h"

enum opcode {
    ST_PUSH, ST_POP,
    ST_SWAP, ST_DUP,
    ST_IADD, ST_ISUB, ST_IMUL, ST_IDIV, ST_INEG,
    ST_IREAD, ST_IPRINT,
    ST_STOP,
};

// Types of the instructions
struct st_noarg {
    enum opcode opcode;
};

struct st_arg64 {
    enum opcode opcode;
    int64_t arg;
};

// Specific opcode refers to the specific instruction type
union instruction {
    enum opcode opcode;
    struct st_noarg as_noarg;
    struct st_arg64 as_arg64;
};

struct interpreter_state {
    const union instruction* ip;
    struct stack* stack;
};

struct interpreter_state state_create(const union instruction* ip, size_t stack_size);

void state_destroy(struct interpreter_state* state);

void interpret(struct interpreter_state* state);

#endif //C_STYOK_H
