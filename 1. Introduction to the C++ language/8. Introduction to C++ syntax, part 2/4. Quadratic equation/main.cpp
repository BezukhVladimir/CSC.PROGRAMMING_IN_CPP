#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double a, b, c, sqrtD, _2a, x1, x2;
    
    cin >> a >> b >> c;
    _2a = 2.0 * a;
    sqrtD = sqrt(b * b - 2.0 * _2a * c);
    
    if (sqrtD > 0.0) {
        x1 = (-b + sqrtD) / _2a;
        x2 = (-b - sqrtD) / _2a;
        cout << x1 << " " << x2 << endl;
    } else if (sqrtD == 0.0) {
        x1 = -b / _2a;
        x2 = x1;
        cout << x1 << " " << x2 << endl;
    } else {
        cout << "No real roots" << endl;
    }
}