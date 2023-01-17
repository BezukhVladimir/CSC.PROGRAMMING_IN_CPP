#include <iostream>

using namespace std;
 
void reverse() {
    int a;
    cin >> a;
    
    if (a) {
        reverse();
        cout << a << ' ';
    }
}
 
int main() {
    reverse();
}