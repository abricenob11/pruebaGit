#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

using Matrix = vector<complex<double>>;

Matrix matmul(const Matrix& A, const Matrix& B, int n) {
    Matrix C(n * n, 0.0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
    return C;
}

Matrix commutator(const Matrix& A, const Matrix& B, int n) {
    Matrix AB = matmul(A, B, n);
    Matrix BA = matmul(B, A, n);
    Matrix result(n * n);
    for (int i = 0; i < n * n; ++i)
        result[i] = AB[i] - BA[i];
    return result;
}

vector<Matrix> getPauliMatrices() {
    complex<double> i(0, 1);
    return {
        {0, 1, 1, 0},             // σ_x
        {0, -i, i, 0},            // σ_y
        {1, 0, 0, -1}             // σ_z
    };
}

void verifyCommutators() {
    auto sigma = getPauliMatrices();
    complex<double> i(0, 1);
    int n = 2;

    const char* names[] = {"σ_x", "σ_y", "σ_z"};

    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
            Matrix comm = commutator(sigma[a], sigma[b], n);

            cout << "[" << names[a] << ", " << names[b] << "] =\n";
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c)
                    cout << comm[r * n + c] << " ";
                cout << "\n";
            }
            cout << "\n";
        }
    }
}


vector<double> vandermondeMatrix(const vector<double>& x, int n) {
    vector<double> V(n * n, 0.0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            V[i * n + j] = pow(x[i], j);
    return V;
}

double trace(const vector<double>& M, int n) {
    double tr = 0.0;
    for (int i = 0; i < n; ++i)
        tr += M[i * n + i];
    return tr;
}