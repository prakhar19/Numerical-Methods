#include <iostream>
using namespace std;

int main() {
    int m = 1, n = 1;

    cout << "Enter size of matrix" << endl;
    cin >> m;
    cin >> n;

    double mat[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < m-1; i++) {
        for (int j = i+1; j < n; j++) {
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