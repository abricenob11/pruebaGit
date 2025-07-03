#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;


//A continuación presento una implementación completa en C++ para calcular 
//el producto cruz entre dos vectores 3D y determinar el ángulo entre ellos:


// Función para calcular el producto cruz entre dos vectores 3D
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

// Función para calcular el ángulo entre dos vectores (en radianes)
double angleBetweenVectors(const vector<double>& A, const vector<double>& B) {
    // Calculamos el producto cruz y su magnitud
    vector<double> cross = crossProduct(A, B);
    double crossMag = vectorMagnitude(cross);
    
    // Calculamos las magnitudes de los vectores
    double aMag = vectorMagnitude(A);
    double bMag = vectorMagnitude(B);
    
    // Evitamos división por cero
    if (aMag == 0 || bMag == 0) {
        cerr << "Error: Uno de los vectores tiene magnitud cero" << endl;
        return 0.0;
    }
    
    // Calculamos el ángulo usando asin(|A×B|/(|A||B|))
    return asin(crossMag / (aMag * bMag));
}

// Función para imprimir un vector
void printVector(const vector<double>& v) {
    cout << "(";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << ")";
}

int main() {
    // Casos de prueba
    vector<double> A = {1, 0, 0};  // Vector unitario i
    vector<double> B = {0, 1, 0};  // Vector unitario j
    vector<double> C = {0, 0, 1};  // Vector unitario k
    vector<double> D = {1, 2, 3};
    vector<double> E = {4, 5, 6};
    
    // Prueba 1: i × j = k
    cout << "Test 1: i × j = k" << endl;
    vector<double> result1 = crossProduct(A, B);
    cout << "Resultado: "; printVector(result1); cout << endl;
    
    // Prueba 2: j × k = i
    cout << "\nTest 2: j × k = i" << endl;
    vector<double> result2 = crossProduct(B, C);
    cout << "Resultado: "; printVector(result2); cout << endl;
    
    // Prueba 3: k × i = j
    cout << "\nTest 3: k × i = j" << endl;
    vector<double> result3 = crossProduct(C, A);
    cout << "Resultado: "; printVector(result3); cout << endl;
    
    // Prueba 4: A × A = 0
    cout << "\nTest 4: A × A = 0" << endl;
    vector<double> result4 = crossProduct(A, A);
    cout << "Resultado: "; printVector(result4); cout << endl;
    
    // Prueba 5: Ángulo entre i y j (debería ser π/2)
    cout << "\nTest 5: Ángulo entre i y j" << endl;
    double angle1 = angleBetweenVectors(A, B);
    cout << "Ángulo: " << angle1 << " rad (" << angle1 * 180/M_PI << "°)" << endl;
    
    // Prueba 6: Ángulo entre D y E
    cout << "\nTest 6: Ángulo entre (1,2,3) y (4,5,6)" << endl;
    double angle2 = angleBetweenVectors(D, E);
    cout << "Ángulo: " << angle2 << " rad (" << angle2 * 180/M_PI << "°)" << endl;
    
    return 0;
}

/*Test 1: i × j = k
Resultado: (0, 0, 1)

Test 2: j × k = i
Resultado: (1, 0, 0)

Test 3: k × i = j
Resultado: (0, 1, 0)

Test 4: A × A = 0
Resultado: (0, 0, 0)

Test 5: Ángulo entre i y j
Ángulo: 1.5708 rad (90°)

Test 6: Ángulo entre (1,2,3) y (4,5,6)
Ángulo: 0.225726 rad (12.9332°)*/