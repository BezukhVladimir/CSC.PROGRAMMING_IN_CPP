#include <cstddef>
#include <cstring>

struct String {
    String(const char * source = "") {
        size = strlen(source);
        str = new char[size + 1];
        strcpy(str, source); 
    }
    
    size_t size;
    char * str;
};