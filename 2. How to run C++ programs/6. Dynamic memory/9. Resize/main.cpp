char * resize(const char * str,
              const unsigned &size,
              const unsigned &new_size) {
    char * new_str = new char[new_size];
    
    size_t min = size < new_size ? size : new_size;
    for (size_t i = 0; i < min; new_str[i] = str[i], ++i);
    new_str[min] = '\0';
    
    delete [] str;
    str = nullptr;
    
    return new_str;
}