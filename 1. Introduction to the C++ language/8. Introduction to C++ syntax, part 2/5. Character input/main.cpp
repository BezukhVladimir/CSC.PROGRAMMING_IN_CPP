#include <iostream>

using namespace std;

int main()
{
    char c, t = '\0';
    while (cin.get(c)) {
        if (t != ' ' || c != ' ')
            cout << c;
        
        t = c;
    }
}