#include <iostream>

template <typename Type>
void flatten(const Array<Type> &array, std::ostream &out) {
    for (size_t i = 0, size = array.size(); i < size; ++i)
        out << array[i] << ' ';
}

template <typename Type>
void flatten(const Array<Array<Type>> &array, std::ostream &out) {
    for (size_t i = 0, size = array.size(); i < size; ++i)
        flatten(array[i], out);
}