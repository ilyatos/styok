#ifndef C_STACK_H
#define C_STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../maybe_int64/maybe_int64.h"

struct stack;

struct stack* stack_create(size_t);

void stack_destroy(struct stack*);

bool stack_is_full(const struct stack*);

bool stack_is_empty(const struct stack*);

bool stack_push(struct stack*, int64_t);

struct maybe_int64 stack_pop(struct stack*);

#endif //C_STACK_H
