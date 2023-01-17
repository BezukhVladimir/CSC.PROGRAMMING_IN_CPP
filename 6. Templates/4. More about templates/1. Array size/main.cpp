#include <cstddef>

template <typename A, size_t size>
size_t array_size(A (&array)[size]) {
    return size;
}