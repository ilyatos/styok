#ifndef C_LIST_H
#define C_LIST_H

#include <inttypes.h>

struct list;

struct list* list_create(int64_t value);

void list_destroy(struct list* list);

void list_add_front(struct list** list, int64_t value);

void list_remove_front(struct list** list);

struct maybe_int64 list_get_front(struct list* list);

#endif //C_LIST_H
