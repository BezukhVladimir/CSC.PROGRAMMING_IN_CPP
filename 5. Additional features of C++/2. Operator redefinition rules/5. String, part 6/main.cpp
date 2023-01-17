#include <cstddef>

struct String
{
    char * str;
    size_t size;
	
    String(const char* str = "");
    String(size_t n, char c);
    ~String();

    String(const String& other);
    String& operator=(const String& other);

    void append(const String& other);

    struct SubStr;
    SubStr operator[](size_t i) const;
};

struct String::SubStr
{
    String substr;
    size_t shift;
    
    SubStr(const String &substr_,
           const size_t &shift_)
        : substr(substr_), shift(shift_) {}

    String operator[](size_t i) {
        substr.str[i - shift] = 0;
        return String(substr.str);
    }
};

String::SubStr String::operator[](size_t i) const {
    return String::SubStr(String(str + i), i);
}