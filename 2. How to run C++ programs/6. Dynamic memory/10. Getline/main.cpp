#include <iostream>

char * resize(const char * str,
              const unsigned &size,
              const unsigned &new_size) {
    char * new_str = new char[new_size];
    
    size_t min = size < new_size ? size : new_size;
    for (size_t i = 0; i < min; new_str[i] = str[i], ++i);
    new_str[min] = '\0';
    
    delete [] str;
    
    return new_str;
}

char * getline() {
    unsigned current_size = 10;
    char * line = new char[current_size];
    
    char c;
    unsigned i = 0;
    for (; std::cin.get(c) && c != '\n'; ++i) {
        line[i] = c;
        
        if (i == current_size - 2) {
	    unsigned new_size = current_size * 1.5;
            line = resize(line, current_size, new_size);
            current_size = new_size;
	}
    }
    
    line[i] = '\0';
    return resize(line, current_size, i + 1);
}