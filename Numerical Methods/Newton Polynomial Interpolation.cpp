#include <iostream>

using namespace std;

double calcForwardDividedDifferences(int, int, double *, double *);
double calcNewtonBasis(double, int, int, double *);

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
        result += calcForwardDividedDifferences(0, i, X, Y) * calcNewtonBasis(x, i, n, X);
    }

    cout << result;
    return 0;
}

double calcForwardDividedDifferences(int v, int vj, double *X, double *Y) {
    if (v == vj) {
        return Y[v];
    }

    // double a1 = 0.0, a2 = 0.0, result;

    // for (int i = v; i < vj; i++) {
    //     a1 += Y[i+1];
    //     a2 += Y[i];
    // }

    // result = (a1 - a2) / (X[vj] - X[v]);

    // return result;

    return (calcForwardDividedDifferences(v+1, vj, X, Y) - calcForwardDividedDifferences(v, vj-1, X, Y)) / (X[vj] - X[v]);
}

double calcNewtonBasis(double x, int j, int n, double *X) {
    if (j == 0) {
        return 1.0;
    }
    double result = 1.0;

    for (int i = 0; i < j; i++) {
        result *= (x - X[i]);
    }

    return result;
}