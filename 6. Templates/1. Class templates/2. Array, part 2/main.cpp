#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class Array
{
private:
    size_t m_size;
    unsigned char * data;
    
    void swap(Array<T> &arr) {
        std::swap(m_size, arr.m_size);
        std::swap(data, arr.data);
    }
    
public:
    Array(size_t size, const T& value = T()) {
        m_size = size;
        data = new unsigned char [m_size * sizeof(T)];
        T * ptr = (T *) data;
        
        for (size_t i = 0; i < m_size; ++i)
            new (ptr + i) T(value);
    }
    
    Array() {
        m_size = 0;
        data = 0;
    }
    
    Array(const Array<T> &arr) {
        m_size = arr.m_size;
        data = new unsigned char [m_size * sizeof(T)];
        T * ptr = (T *) data;
        
        for (size_t i = 0; i < m_size; ++i)
            new (ptr + i) T(arr[i]);
    }
    
    ~Array() {
        T * ptr = (T *) data;
        
        for (size_t i = 0; i < m_size; ++i)
            ptr[i].~T();
        
        delete [] data;
    }   
    
    Array& operator=(const Array<T> &arr) {
        if (this != &arr) {
            Array<T> temp(arr);
            temp.swap(*this);
        }
        
        return *this;
    }
     
    size_t size() const {
        return m_size;
    }
        
    T& operator[](size_t i) {
        T * ptr = (T *) data;
        return *(ptr + i);
    }
    
    const T& operator[](size_t i) const {
        T * ptr = (T *) data;
        return *(ptr + i);
    }    
};