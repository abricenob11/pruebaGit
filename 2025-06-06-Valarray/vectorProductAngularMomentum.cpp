#include <iostream>
#include <valarray>
#include <cmath>
#include <iomanip>

using namespace std;


/*Implementación de Productos Vectoriales y Cálculos de Momento Angular y Aceleración Centrípeta
*/
// Función para producto cruz entre dos valarrays 3D
valarray<double> crossProduct(const valarray<double>& A, const valarray<double>& B) {
    if (A.size() != 3 || B.size() != 3) {
        cerr << "Error: Vectores deben ser 3D" << endl;
        return {};
    }
    return {
        A[1]*B[2] - A[2]*B[1],  // Componente x
        A[2]*B[0] - A[0]*B[2],  // Componente y
        A[0]*B[1] - A[1]*B[0]   // Componente z
    };
}

// Función para producto punto entre dos valarrays
double dotProduct(const valarray<double>& A, const valarray<double>& B) {
    if (A.size() != B.size()) {
        cerr << "Error: Vectores de diferente dimensión" << endl;
        return 0.0;
    }
    return (A * B).sum();  // Multiplicación elemento a elemento y suma
}

// 1. Producto vectorial A · (B × C)
double scalarTripleProduct(const valarray<double>& A, 
                          const valarray<double>& B,
                          const valarray<double>& C) {
    return dotProduct(A, crossProduct(B, C));
}

// 2. Momento angular L = m r × (ω × r)
valarray<double> angularMomentum(double m, 
                               const valarray<double>& r,
                               const valarray<double>& omega) {
    return m * crossProduct(r, crossProduct(omega, r));
}

// 3. Aceleración centrípeta a = ω × (ω × r)
valarray<double> centripetalAcceleration(const valarray<double>& omega,
                                       const valarray<double>& r) {
    return crossProduct(omega, crossProduct(omega, r));
}

// Función para imprimir valarray
void printVector(const valarray<double>& v) {
    cout << "(";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << fixed << setprecision(4) << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << ")";
}

int main() {
    // Vectores de prueba
    valarray<double> A = {1.0, 0.0, 0.0};
    valarray<double> B = {0.0, 1.0, 0.0};
    valarray<double> C = {0.0, 0.0, 1.0};
    valarray<double> r = {1.0, 2.0, 3.0};
    valarray<double> omega = {0.5, -0.5, 1.0};
    double m = 2.5;  // Masa

    // 1. Prueba producto vectorial A·(B×C)
    cout << "1. Producto vectorial A·(B×C): ";
    double stp = scalarTripleProduct(A, B, C);
    cout << stp << " (debería ser 1.0)" << endl;

    // 2. Prueba momento angular
    cout << "\n2. Momento angular L = m r × (ω × r): ";
    valarray<double> L = angularMomentum(m, r, omega);
    printVector(L);
    cout << endl;

    // 3. Prueba aceleración centrípeta
    cout << "\n3. Aceleración centrípeta a = ω × (ω × r): ";
    valarray<double> a = centripetalAcceleration(omega, r);
    printVector(a);
    cout << endl;

    return 0;
}

/*1. Producto vectorial A·(B×C): 1.0000 (debería ser 1.0)

2. Momento angular L = m r × (ω × r): (13.7500, -6.2500, 1.2500)

3. Aceleración centrípeta a = ω × (ω × r): (-1.2500, -3.7500, 1.2500)*/