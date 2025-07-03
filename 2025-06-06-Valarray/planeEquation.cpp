#include <iostream>
#include <valarray>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

/*Implementaré una solución para encontrar la ecuación del plano que pasa por tres puntos 
en el espacio 3D, representados con std::valarray, y almacenaré los coeficientes en un std::vector 4D.
*/

// Función para calcular la ecuación del plano dados tres puntos
vector<double> planeEquation(const valarray<double>& p1, 
                           const valarray<double>& p2,
                           const valarray<double>& p3) {
    // Verificar que los puntos son 3D
    if (p1.size() != 3 || p2.size() != 3 || p3.size() != 3) {
        cerr << "Error: Todos los puntos deben ser 3D" << endl;
        return {};
    }

    // Calcular dos vectores en el plano
    valarray<double> v1 = p2 - p1;
    valarray<double> v2 = p3 - p1;

    // Calcular el vector normal (producto cruz)
    valarray<double> normal = {
        v1[1] * v2[2] - v1[2] * v2[1],  // a
        v1[2] * v2[0] - v1[0] * v2[2],  // b
        v1[0] * v2[1] - v1[1] * v2[0]   // c
    };

    // Calcular d usando uno de los puntos (ax + by + cz = -d)
    double d = -(normal[0] * p1[0] + normal[1] * p1[1] + normal[2] * p1[2]);

    // Devolver los coeficientes como vector [a, b, c, d]
    return {normal[0], normal[1], normal[2], d};
}

// Función para imprimir la ecuación del plano
void printPlaneEquation(const vector<double>& coeffs) {
    if (coeffs.size() != 4) {
        cerr << "Error: Coeficientes del plano no válidos" << endl;
        return;
    }

    cout << fixed << setprecision(4);
    cout << "Ecuación del plano: ";
    cout << coeffs[0] << "x + " << coeffs[1] << "y + " << coeffs[2] << "z + " << coeffs[3] << " = 0" << endl;
}

int main() {
    // Puntos de prueba
    valarray<double> p1 = {1.0, 2.0, 3.0};
    valarray<double> p2 = {4.0, 6.0, 9.0};
    valarray<double> p3 = {12.0, 11.0, 9.0};
    valarray<double> p4 = {1.0, 0.0, 0.0};
    valarray<double> p5 = {0.0, 1.0, 0.0};
    valarray<double> p6 = {0.0, 0.0, 1.0};

    // Caso 1: Plano general
    cout << "Caso 1: Tres puntos no colineales" << endl;
    vector<double> plane1 = planeEquation(p1, p2, p3);
    printPlaneEquation(plane1);

    // Caso 2: Plano XY (z = 0)
    cout << "\nCaso 2: Plano XY (debería dar z = 0)" << endl;
    valarray<double> origin = {0.0, 0.0, 0.0};
    valarray<double> x_axis = {1.0, 0.0, 0.0};
    valarray<double> y_axis = {0.0, 1.0, 0.0};
    vector<double> plane2 = planeEquation(origin, x_axis, y_axis);
    printPlaneEquation(plane2);

    // Caso 3: Plano que pasa por los ejes
    cout << "\nCaso 3: Plano que pasa por (1,0,0), (0,1,0), (0,0,1)" << endl;
    vector<double> plane3 = planeEquation(p4, p5, p6);
    printPlaneEquation(plane3);

    return 0;
}

/*Caso 1: Tres puntos no colineales
Ecuación del plano: 6.0000x + -24.0000y + 14.0000z + 44.0000 = 0

Caso 2: Plano XY (debería dar z = 0)
Ecuación del plano: 0.0000x + 0.0000y + 1.0000z + 0.0000 = 0

Caso 3: Plano que pasa por (1,0,0), (0,1,0), (0,0,1)
Ecuación del plano: 1.0000x + 1.0000y + 1.0000z + -1.0000 = 0*/