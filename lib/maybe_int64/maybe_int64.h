#ifndef C_MAYBE_INT64_H
#define C_MAYBE_INT64_H

#include <inttypes.h>
#include <stdbool.h>

struct maybe_int64 {
    bool valid;
    int64_t value;
};

const struct maybe_int64 none_int64;

struct maybe_int64 some_int64(int64_t value);

#endif //C_MAYBE_INT64_H
