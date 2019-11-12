#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x*x;
}

int main() {
    int n = 0;;
    double u, l, delta_x;
    double integral;

    cout << "Enter number of subintervals (n): ";
    cin >> n;

    cout << "Enter lower limit: ";
    cin >> l;

    cout << "Enter upper limit: ";
    cin >> u;

    delta_x = (u + l) / n;

    integral = 0.0;
    for (int i = 0; i < n; i++) {
        integral += f( l + (i * delta_x) ) + f( l + ((i+1) * delta_x) );
    }

    integral = (delta_x / 2.0) * integral;

    cout << "Integral: " << integral << endl;
    
    return 0;
}