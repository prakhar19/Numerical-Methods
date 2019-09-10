#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m = 1, n = 1;
    double max;
    int index;
    double temp;

    cout << "Enter size of matrix" << endl;
    cin >> m;
    cin >> n;

    double mat[m][n];
    double S[m];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        S[i] = mat[i][0]; 
        for (int j = 0; j < n - 1; j++) {
            S[i] = (mat[i][j] > S[i]) ? mat[i][j] : S[i];
        }
    }

    for (int i = 0; i < m-1; i++) {
        /** Partial Pivoting **/
        index = i;
        max = abs(mat[index][i]) / S[index];

        for (int j = i; j < m; j++) {
            if ((abs(mat[j][i]) / S[j]) > max) {
                max = abs(mat[j][i]) / S[j];
                index = j;
            }
        }
        
        if (index != i) {
            for (int j = 0; j < n; j++) {
                temp = mat[index][j];
                mat[index][j] = mat[i][j];
                mat[i][j]= temp;
            }

            temp = S[i];
            S[i] = S[index];
            S[index] = temp;
        }

        for (int j = i+1; j < m; j++) {
            /** Gaussian Elimination **/
            double factor = mat[j][i] / mat[i][i];

            for (int k = 0; k < n; k++) {
                mat[j][k] -= mat[i][k] * factor;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}