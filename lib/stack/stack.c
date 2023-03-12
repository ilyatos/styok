#include "stack.h"
#include "list.h"

struct stack {
    size_t size;
    size_t count;
    struct list* list;
};

struct stack* stack_create(size_t size) {
    struct stack* stack = malloc(sizeof(struct stack));
    stack->size = size;
    return stack;
}

void stack_destroy(struct stack* s) {
    list_destroy(s->list);
    free(s);
}

bool stack_is_full(const struct stack* s) {
    return s->count == s->size;
}

bool stack_is_empty(const struct stack* s) {
    return s->count == 0;
}

bool stack_push(struct stack* s, int64_t value) {
    if (stack_is_full(s)) return false;

    s->list ? list_add_front(&s->list, value) : (s->list = list_create(value));
    ++s->count;

    return true;
}

struct maybe_int64 stack_pop(struct stack* s) {
    if (stack_is_empty(s)) return none_int64;

    struct maybe_int64 value = list_get_front(s->list);
    list_remove_front(&s->list);
    --s->count;

    return value;
}