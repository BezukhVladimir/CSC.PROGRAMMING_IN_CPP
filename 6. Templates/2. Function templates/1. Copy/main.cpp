#include <cstddef>

template <typename U, typename T>
void copy_n(T *t, U *u, size_t s) {
    for (size_t i = 0; i < s; ++i)
        t[i] = static_cast<T>(u[i]);
}