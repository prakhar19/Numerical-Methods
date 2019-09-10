#define MAX_ITERATIONS 1000
#define TOLERANCE 0.0000000001
#define OMEGA 0.5

#include <iostream>
#include <math.h>
using namespace std;


void input();
long double* diffMat(long double *, long double *, int);
long double L2norm(long double *, int);

int m = 1, n = 1;
long double **mat;


int main() {
    input();
    
    long double x[m] = {0L}, xold[m] = {0L};
    long double s1 = 0L, s2 = 0L;
    
    int iter;
    for (iter = 0; iter < MAX_ITERATIONS; iter++) {
        for (int i = 0; i < m; i++) {
            s1 = 0L;
            for (int j = 0; j < i; j++) {
                s1 += mat[i][j] * x[j];
            }

            s2 = 0L;
            for (int j = i+1; j < n-1; j++) {
                s2 += mat[i][j] * xold[j];
            }
            
            x[i] = (1 - OMEGA) * xold[i] + OMEGA * (mat[i][n-1] - s1 - s2) / mat[i][i];
        }
        
        if (L2norm(diffMat(x, xold, m), m) < TOLERANCE) {
            break;
        }

        for (int i = 0; i < m; i++) {
            xold[i] = x[i];
        }
    }
    
    cout << "Converged in " << (iter + 1) << " iterations." << endl;

    for (int i = 0; i < m; i++) {
        cout << "x" << i << " = " << x[i] << endl;
    }

    return 0;
}

void input() {
    long double temp = 0.0L;

    cout << "Enter size of the matrix" << endl;
    cin >> m;
    n = m + 1;
    
    mat = new long double *[m];
    for (int i = 0; i < m; i++) {
        mat[i] = new long double[n]{0L};
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    // Display
    cout << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

long double* diffMat(long double *a, long double *b, int size) {
    long double *output = new long double[size]{0L};
    
    for (int i = 0; i < size; i++) {
        output[i] = a[i] - b[i];
    }

    return output;
}

long double L2norm(long double *vector, int size) {
    long double norm = 0.0L;

    for (int i = 0; i < size; i++) {
        norm = vector[i] * vector[i];
    }

    return sqrt(norm);
}