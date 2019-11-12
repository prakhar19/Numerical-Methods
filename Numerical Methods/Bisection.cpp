#define EPSILON 0.00000001

#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return x * x * x;
}

int main() {
    double a, b, c;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    if (f(a) == 0) {
        cout << "Root: " << c << endl;
        return 0;
    }
    if (f(b) == 0) {
        cout << "Root: " << c << endl;
        return 0;
    }

    if (f(a) * f(b) > 0) {
        cout << "f(a) and f(b) both have same sign." << endl;
        return 1;
    }

    while (abs(b - a) >= EPSILON) {
        c = (a + b) / 2.0;

        if (f(c) == 0) {
            break;
        } else if (f(a) * f(c) > 0) {
            a = c;
        } else {
            b = c;
        }
    }

    cout << "Root: " << c << endl;

    return 0;
}