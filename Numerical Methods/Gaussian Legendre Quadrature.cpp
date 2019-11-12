#define EPSILON 0.00000001

#include <iostream>
#include <math.h>

using namespace std;

double legendre(int, double);
double legendre_derivative(int, double);
void get_roots_of_legendre_polynomial(int, double *);

double f(double x) {
    return cos(x);
}

int main() {
    int n;
    double u, l, weight = 0.0;
    double result = 0.0;
    double *roots, *weights;

    cout << "Enter n (exact for polynomials of degree 2n-1 or less): ";
    cin >> n;

    roots = new double[n];
    weights = new double[n];

    cout << "Enter upper limit: ";
    cin >> u;

    cout << "Enter lower limit: ";
    cin >> l;

    cout << endl;

    // Get roots of Legendre Polynomial P_n(x)
    get_roots_of_legendre_polynomial(n, roots);
    cout << endl;
    // Calculate weights
    cout << "Weights: ";
    for (int i = 0; i < n; i++) {
        weights[i] = 2 / ( (1-pow(roots[i], 2)) * pow(legendre_derivative(n, roots[i]), 2) );
        cout << weights[i] << ", ";
    }
    cout << endl << endl;

    // Aproximating the integral
    for (int i = 0; i < n; i++) {
        result += weights[i] * f(((u-l) * roots[i] / 2) + (u+l)/2);
    }
    result *= (u-l) / 2;

    cout << "Result: " << result << endl;

    return 0;
}

double legendre(int n, double x) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    }
    
    return (((2*n - 1) * x * legendre(n-1, x)) - ((n-1) * legendre(n-2, x))) / n;
}

double legendre_derivative(int n, double x) {
    return (((x * n) / (x*x - 1)) * legendre(n, x)) - ((n / (x*x - 1)) * legendre(n-1, x));
}

void get_roots_of_legendre_polynomial(int n, double *roots) {
    // Uses Newton Raphson
    double x, prev_x;

    cout << "Roots: ";
    for (int i = 0; i < n; i++) {
        x = cos(M_PI * ((i - 0.25) / (n + 0.5)));

        prev_x = x;
        x = x - (legendre(n, x) / legendre_derivative(n, x));
        
        while (abs(x - prev_x) >= EPSILON) {
            prev_x = x;
            x = x - (legendre(n, x) / legendre_derivative(n, x));
        }

        cout << x << ", ";
        roots[i] = x;
    }
    cout << endl;
}