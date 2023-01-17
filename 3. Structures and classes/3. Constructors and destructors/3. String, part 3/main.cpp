#include <cstddef>
#include <cstring>

struct String
{
    String(const char *str = "");
    String(size_t n, char c);
    ~String();
    
    void append(String &other) {
	size += other.size;
	char * temp_str = new char[size + 1];
	strcpy(temp_str, str);
	strcat(temp_str, other.str);
	    
	delete [] str;
	str = temp_str;
    }

    size_t size;
    char * str;
};