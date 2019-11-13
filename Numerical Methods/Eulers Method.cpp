#include <iostream>
#include <cmath>

using namespace std;



long double f(long double x, long double y) {
    return 0.0308 - 0.002 * (52.1*y + 10.3/(10.3 + y)) + 1.17 * (1 + sin(3*x));
}

int main() {
    long double result = 0.0, h, x0, y0, x;
    
    cout << "Define step size: ";
    cin >> h;

    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter y0: ";
    cin >> y0;

    cout << "Enter final x: ";
    cin >> x;


    result = y0;
    for (long double i = x0; i <= x; i += h)
    {
        cout << "(" << i << ", " << result << "), ";
        result += h * f(i, result);
    }

    return 0;
}