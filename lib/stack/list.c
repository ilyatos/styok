#include <malloc/_malloc.h>
#include "list.h"
#include "../maybe_int64/maybe_int64.h"

struct list {
    int64_t value;
    struct list* next;
};

void list_destroy(struct list* list) {
    if (!list) return;
    list_destroy(list->next);
    free(list);
}

static struct list* list_node_create(int64_t value) {
    struct list* list = malloc(sizeof(struct list));
    list->value = value;
    return list;
}

struct list* list_create(int64_t value) {
    return list_node_create(value);
}

void list_add_front(struct list** list, int64_t value) {
    struct list* new = list_node_create(value);
    new->next = *list;
    *list = new;
}

void list_remove_front(struct list** list) {
    struct list* old = *list;
    *list = (*list)->next;
    free(old);
}

struct maybe_int64 list_get_front(struct list* list) {
    if (!list) return none_int64;
    return some_int64(list->value);
}