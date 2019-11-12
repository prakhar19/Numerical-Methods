#include <iostream>

using namespace std;


double calcLagrange(double, int, int, double *);

int main() {
    int n;
    double x;

    cout << "Enter the number of points: ";
    cin >> n;

    double *X = new double[n], *Y = new double[n];

    for (int i = 0; i < n; i ++) {
        cout << "x" << (i+1) << ": ";
        cin >> X[i];

        cout << "y" << (i+1) << ": ";
        cin >> Y[i];
    }

    cout << "Enter the unknown x-value to interpolate: ";
    cin >> x;

    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += Y[i] * calcLagrange(x, i, n, X);
    }

    cout << result;
    return 0;
}

double calcLagrange(double x, int j, int n, double *X) {
    double result = 1.0;

    for (int i = 0; i < n; i++) {
        if (i == j) {
            continue;
        }

        result *= (x - X[i]) / (X[j] - X[i]);
    }

    return result;
}