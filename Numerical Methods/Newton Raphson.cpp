#define EPSILON 0.00000001

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x * x;
}

double f_dash(double x) {
    return 3 * x * x;
}

int main() {
    double x, prev_x;

    cout << "Enter x: ";
    cin >> x;

    prev_x = x;
    x = x - (f(x) / f_dash(x));
    
    while (abs(x - prev_x) >= EPSILON) {
        prev_x = x;
        x = x - (f(x) / f_dash(x));
    }

    cout << "Root: " << x << endl;

    return 0;
}