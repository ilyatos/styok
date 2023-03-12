#include "maybe_int64.h"

const struct maybe_int64 none_int64 = {0};

struct maybe_int64 some_int64(int64_t value) {
    return (struct maybe_int64) {.valid = true, .value = value};
}

