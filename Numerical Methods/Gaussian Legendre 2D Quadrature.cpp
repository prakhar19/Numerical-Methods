#define EPSILON 0.0000000001

#include <iostream>
#include <math.h>

using namespace std;

long double legendre(int, long double);
long double legendre(int, long double, long double *, int *);
long double legendre_optimized(int, long double);
long double legendre_derivative(int, long double);
void get_roots_of_legendre_polynomial(int, long double *);

long double f(long double x, long double y) {
    return x * x + y * y;
}

int main() {
    int n;
    long double ux, lx, uy, ly, weight = 0.0;
    long double result = 0.0;
    long double *roots, *weights;

    cout << "Enter n (exact for polynomials of degree 2n-1 or less): ";
    cin >> n;

    roots = new long double[n];
    weights = new long double[n];


    cout << "Integral is of the form ∫∫ f(x, y) dxdy" << endl;

    cout << "Enter upper limit (for dx): ";
    cin >> ux;

    cout << "Enter lower limit (for dx): ";
    cin >> lx;

    cout << "Enter upper limit (for dy): ";
    cin >> uy;

    cout << "Enter lower limit (for dy): ";
    cin >> ly;

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
        for (int j = 0; j < n; j++) {
            result += weights[i] * weights[j] * f(((ux-lx)*roots[i]/2)+(ux+lx)/2, ((uy-ly)*roots[i]/2)+(uy+ly)/2);
        }
    }
    result *= (ux-lx) * (uy-ly) / 4;

    cout << "Result: " << result << endl;

    return 0;
}

long double legendre(int n, long double x) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    }
    
    return (((2*n - 1) * x * legendre(n-1, x)) - ((n-1) * legendre(n-2, x))) / n;
}

long double legendre(int n, long double x, long double *values, int *optimize) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    }
    
    if (optimize[n] == 1) {
        return values[n];
    }
    
    long double result = (((2*n - 1) * x * legendre(n-1, x, values, optimize)) - ((n-1) * legendre(n-2, x, values, optimize))) / n;

    values[n] = result;
    optimize[n] = 1;
    
    return result;
}

long double legendre_optimized(int n, long double x) {
    long double values[n+1] = {};
    int optimize[n+1] = {};
    
    return legendre(n, x, values, optimize);
}


long double legendre_derivative(int n, long double x) {
    return (((x * n) / (x*x - 1)) * legendre_optimized(n, x)) - ((n / (x*x - 1)) * legendre_optimized(n-1, x));
}

void get_roots_of_legendre_polynomial(int n, long double *roots) {
    // Uses Newton Raphson
    long double x, prev_x;

    cout << "Roots: ";
    for (int i = 0; i < n; i++) {
        x = cos(M_PI * ((i - 0.25) / (n + 0.5)));

        prev_x = x;
        x -= legendre_optimized(n, x) / legendre_derivative(n, x);
        
        while (abs(x - prev_x) >= EPSILON) {
            prev_x = x;
            x -= legendre_optimized(n, x) / legendre_derivative(n, x);
        }

        cout << x << ", ";
        roots[i] = x;
    }
    cout << endl;
}