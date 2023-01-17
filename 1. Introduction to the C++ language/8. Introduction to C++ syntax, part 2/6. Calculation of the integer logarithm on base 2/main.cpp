#include <iostream>

using namespace std;

int main()
{
    unsigned T, a, p;
    
    for (cin >> T; cin >> a;)
    {
        p = 0;
        
        while (a >>= 1)
            ++p;
        
        cout << p << endl;
    }
}