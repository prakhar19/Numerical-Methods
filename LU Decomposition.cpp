#include <iostream>

using namespace std;

int main() {
    int n = 1;
    double temp = 0.0;

    cout << "Enter size of the matrix" << endl;
    cin >> n;

    double mat[n][n] = {};
    double L[n][n] = {}, U[n][n] = {};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        L[i][i] = 1;
    }
    
    cout << L[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                temp = 0.0;
                for (int k = 0; k < i; k++){
                    temp += L[i][k] * U[k][j];
                }

                L[i][j] = (mat[i][j] - temp) / U[j][j];    
            }

            if (j >= i) {
                temp = 0.0;
                for (int k = 0; k < i; k++) {
                    temp += L[i][k] * U[k][j];
                }
                
                U[i][j] = mat[i][j] - temp;
            }
        }
    }

    cout << endl;
    cout << "L matrix :" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "U matrix :" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}