#include <stdio.h>
#include "stack/stack.h"
#include "interpreter.h"

struct interpreter_state state_create(const union instruction* ip, size_t stack_size) {
    return (struct interpreter_state) {.ip = ip, .stack = stack_create(stack_size)};
}

void state_destroy(struct interpreter_state* state) {
    stack_destroy(state->stack);
}

typedef void interpreter_handler(struct interpreter_state*);

void handler_push(struct interpreter_state* state) {
    stack_push(state->stack, state->ip->as_arg64.arg);
}

void handler_pop(struct interpreter_state* state) {
    stack_pop(state->stack);
}

void handler_swap(struct interpreter_state* state) {
    struct maybe_int64 value_f = stack_pop(state->stack);
    struct maybe_int64 value_s = stack_pop(state->stack);
    if (!value_f.valid || !value_s.valid) return;

    stack_push(state->stack, value_f.value);
    stack_push(state->stack, value_s.value);
}

void handler_duplicate(struct interpreter_state* state) {
    const struct maybe_int64 value = stack_pop(state->stack);
    if (!value.valid) return;

    stack_push(state->stack, value.value);
    stack_push(state->stack, value.value);
}

void handler_add(struct interpreter_state* state) {
    struct maybe_int64 value_f = stack_pop(state->stack);
    struct maybe_int64 value_s = stack_pop(state->stack);
    if (!value_f.valid || !value_s.valid) return;

    stack_push(state->stack, value_s.value + value_f.value);
}

void handler_subtract(struct interpreter_state* state) {
    struct maybe_int64 value_f = stack_pop(state->stack);
    struct maybe_int64 value_s = stack_pop(state->stack);
    if (!value_f.valid || !value_s.valid) return;

    stack_push(state->stack, value_s.value - value_f.value);
}

void handler_multiply(struct interpreter_state* state) {
    struct maybe_int64 value_f = stack_pop(state->stack);
    struct maybe_int64 value_s = stack_pop(state->stack);
    if (!value_f.valid || !value_s.valid) return;

    stack_push(state->stack, value_s.value * value_f.value);
}

void handler_divide(struct interpreter_state* state) {
    struct maybe_int64 value_f = stack_pop(state->stack);
    struct maybe_int64 value_s = stack_pop(state->stack);
    if (!value_f.valid || !value_s.valid) return;

    stack_push(state->stack, value_s.value / value_f.value);
}

void handler_negate(struct interpreter_state* state) {
    struct maybe_int64 value = stack_pop(state->stack);
    if (!value.valid) return;

    stack_push(state->stack, -value.value);
}

void handler_read(struct interpreter_state* state) {
    int64_t value;
    scanf("%" SCNd64, &value);
    stack_push(state->stack, value);
}

void handler_print(struct interpreter_state* state) {
    struct maybe_int64 value = stack_pop(state->stack);
    if (!value.valid) return;

    printf("%" PRId64 "\n", value.value);
}

interpreter_handler* handlers[] = {
        [ST_PUSH] = handler_push,
        [ST_POP] = handler_pop,
        [ST_SWAP] = handler_swap,
        [ST_DUP] = handler_duplicate,
        [ST_IADD] = handler_add,
        [ST_ISUB] = handler_subtract,
        [ST_IMUL] = handler_multiply,
        [ST_IDIV] = handler_divide,
        [ST_INEG] = handler_negate,
        [ST_IREAD] = handler_read,
        [ST_IPRINT] = handler_print
};

void interpret(struct interpreter_state* state) {
    while (true) {
        handlers[state->ip->opcode](state);
        if (state->ip == NULL) return;
        state->ip++;
    }
}