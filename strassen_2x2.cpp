#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add or subtract two matrices
Matrix add(Matrix arr, Matrix brr, int n, int sign = 1) {
    Matrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = arr[i][j] + sign * brr[i][j];
    return res;
}

// Strassen's matrix multiplication function
Matrix mult(Matrix arr, Matrix brr) {
    int n = arr.size();
    Matrix res(n, vector<int>(n, 0));

    // Base case
    if (n == 1) {
        res[0][0] = arr[0][0] * brr[0][0];
        return res;
    }

    int nwSz = n / 2; // New Size
    Matrix a11(nwSz, vector<int>(nwSz, 0));
    Matrix a12(nwSz, vector<int>(nwSz, 0));
    Matrix a21(nwSz, vector<int>(nwSz, 0));
    Matrix a22(nwSz, vector<int>(nwSz, 0));
    Matrix b11(nwSz, vector<int>(nwSz, 0));
    Matrix b12(nwSz, vector<int>(nwSz, 0));
    Matrix b21(nwSz, vector<int>(nwSz, 0));
    Matrix b22(nwSz, vector<int>(nwSz, 0));

    // Splitting arr and brr into submatrices
    for (int i = 0; i < nwSz; i++)
        for (int j = 0; j < nwSz; j++) {
            a11[i][j] = arr[i][j];
            a12[i][j] = arr[i][j + nwSz];
            a21[i][j] = arr[i + nwSz][j];
            a22[i][j] = arr[i + nwSz][j + nwSz];
            b11[i][j] = brr[i][j];
            b12[i][j] = brr[i][j + nwSz];
            b21[i][j] = brr[i + nwSz][j];
            b22[i][j] = brr[i + nwSz][j + nwSz];
        }

    // Strassen's seven multiplications
    Matrix m1 = mult(add(a11, a22, nwSz), add(b11, b22, nwSz));
    Matrix m2 = mult(add(a21, a22, nwSz), b11);
    Matrix m3 = mult(a11, add(b12, b22, nwSz, -1));
    Matrix m4 = mult(a22, add(b21, b11, nwSz, -1));
    Matrix m5 = mult(add(a11, a12, nwSz), b22);
    Matrix m6 = mult(add(a21, a11, nwSz, -1), add(b11, b12, nwSz));
    Matrix m7 = mult(add(a12, a22, nwSz, -1), add(b21, b22, nwSz));

    // Calculating result submatrices
    Matrix c11 = add(add(m1, m4, nwSz), add(m7, m5, nwSz, -1), nwSz);
    Matrix c12 = add(m3, m5, nwSz);
    Matrix c21 = add(m2, m4, nwSz);
    Matrix c22 = add(add(m1, m3, nwSz), add(m6, m2, nwSz, -1), nwSz);

    // Copy results into result matrix
    for (int i = 0; i < nwSz; i++)
        for (int j = 0; j < nwSz; j++) {
            res[i][j] = c11[i][j];
            res[i][j + nwSz] = c12[i][j];
            res[i + nwSz][j] = c21[i][j];
            res[i + nwSz][j + nwSz] = c22[i][j];
        }

    return res;
}

int main() {
    Matrix arr = {{7, 8}, {2, 9}};
    Matrix brr = {{14, 5}, {5, 18}};
    Matrix res = mult(arr, brr);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
