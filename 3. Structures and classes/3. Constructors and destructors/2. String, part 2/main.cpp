#include <cstddef>
#include <cstring>

struct String
{
    String(const char * source = "") {
        size = strlen(source);
        str = new char[size + 1];
        strcpy(str, source); 
    }
    
    String(const size_t &n,
           const char &c) {
        char * temp_str = new char[n + 1];

        for (unsigned i = 0; i < n; ++i)
            temp_str[i] = c;

        temp_str[n] = '\0';
        size = n;
        str = temp_str; 
    }
    
    ~String() {
        delete [] str;
    }

    size_t size;
    char * str;
};