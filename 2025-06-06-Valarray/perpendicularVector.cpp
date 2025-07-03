#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
//Basándonos en la función de producto cruz implementada anteriormente, crearé una función que 
//encuentre un vector unitario perpendicular a dos vectores dados en el espacio 3D.


// Función de producto cruz (del ejercicio anterior)
vector<double> crossProduct(const vector<double>& A, const vector<double>& B) {
    if (A.size() != 3 || B.size() != 3) {
        cerr << "Error: Los vectores deben ser de dimensión 3" << endl;
        return {};
    }
    
    return {
        A[1] * B[2] - A[2] * B[1],  // Componente x
        A[2] * B[0] - A[0] * B[2],  // Componente y
        A[0] * B[1] - A[1] * B[0]   // Componente z
    };
}

// Función para calcular la magnitud de un vector
double vectorMagnitude(const vector<double>& v) {
    double sum = 0.0;
    for (double component : v) {
        sum += component * component;
    }
    return sqrt(sum);
}

// Función para normalizar un vector (convertirlo en unitario)
vector<double> normalizeVector(const vector<double>& v) {
    double mag = vectorMagnitude(v);
    if (mag == 0.0) {
        cerr << "Error: No se puede normalizar el vector cero" << endl;
        return {0.0, 0.0, 0.0};
    }
    
    return {v[0]/mag, v[1]/mag, v[2]/mag};
}

// Función principal que encuentra un vector unitario perpendicular
vector<double> findPerpendicularUnitVector(const vector<double>& A, const vector<double>& B) {
    // 1. Calcular el producto cruz (que es perpendicular a ambos vectores)
    vector<double> cross = crossProduct(A, B);
    
    // 2. Verificar si el producto cruz es el vector cero (vectores paralelos)
    if (vectorMagnitude(cross) < 1e-10) {
        cerr << "Error: Los vectores son paralelos, no existe un único vector perpendicular" << endl;
        return {0.0, 0.0, 0.0};
    }
    
    // 3. Normalizar el vector resultante
    return normalizeVector(cross);
}

// Función para imprimir un vector
void printVector(const vector<double>& v) {
    cout << "(";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << fixed << setprecision(4) << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << ")";
}

int main() {
    // Casos de prueba
    vector<double> i = {1, 0, 0};
    vector<double> j = {0, 1, 0};
    vector<double> k = {0, 0, 1};
    vector<double> v1 = {1, 2, 3};
    vector<double> v2 = {4, 5, 6};
    
    // Test 1: Vector perpendicular a i y j (debería ser k o -k)
    cout << "Vector perpendicular a i y j: ";
    vector<double> result1 = findPerpendicularUnitVector(i, j);
    printVector(result1);
    cout << " (magnitud: " << vectorMagnitude(result1) << ")" << endl;
    
    // Test 2: Vector perpendicular a j y k (debería ser i o -i)
    cout << "Vector perpendicular a j y k: ";
    vector<double> result2 = findPerpendicularUnitVector(j, k);
    printVector(result2);
    cout << " (magnitud: " << vectorMagnitude(result2) << ")" << endl;
    
    // Test 3: Vector perpendicular a v1 y v2
    cout << "Vector perpendicular a (1,2,3) y (4,5,6): ";
    vector<double> result3 = findPerpendicularUnitVector(v1, v2);
    printVector(result3);
    cout << " (magnitud: " << vectorMagnitude(result3) << ")" << endl;
    
    // Test 4: Vectores paralelos (debería dar error)
    cout << "Vector perpendicular a i e i: ";
    vector<double> result4 = findPerpendicularUnitVector(i, i);
    printVector(result4);
    cout << " (magnitud: " << vectorMagnitude(result4) << ")" << endl;
    
    return 0;
}

/*Vector perpendicular a i y j: (0.0000, 0.0000, 1.0000) (magnitud: 1)
Vector perpendicular a j y k: (1.0000, 0.0000, 0.0000) (magnitud: 1)
Vector perpendicular a (1,2,3) y (4,5,6): (-0.4082, 0.8165, -0.4082) (magnitud: 1)
Error: Los vectores son paralelos, no existe un único vector perpendicular
Vector perpendicular a i e i: (0.0000, 0.0000, 0.0000) (magnitud: 0)*/