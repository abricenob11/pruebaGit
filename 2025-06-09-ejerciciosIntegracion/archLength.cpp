#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
//Parte 1: Longitud de Arco para la Catenaria (y = cosh x)

// Función catenaria y = cosh(x)
double catenary(double x) {
    return cosh(x);
}

// Derivada de la catenaria dy/dx = sinh(x)
double catenary_deriv(double x) {
    return sinh(x);
}

// Integrando para la longitud de arco: sqrt(1 + (dy/dx)^2)
double arc_length_integrand(double x) {
    double dy_dx = catenary_deriv(x);
    return sqrt(1.0 + dy_dx*dy_dx);
}

// Método de Simpson para integración
double simpson_integration(double a, double b, double (*f)(double), int n = 1000) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i % 2 == 0) ? 2.0 * f(x) : 4.0 * f(x);
    }
    
    return sum * h / 3.0;
}

int main() {
    const double a = -1.0;
    const double b = 1.0;
    
    double length = simpson_integration(a, b, arc_length_integrand);
    
    cout << "Longitud de arco de la catenaria entre x=-1 y x=1:" << endl;
    cout << "Resultado numérico: " << setprecision(12) << length << endl;
    cout << "Resultado exacto (2*sinh(1)): " << 2.0*sinh(1.0) << endl;
    
    return 0;
}





//Parte 2: Cadena con forma y = x² y densidad ρ(x) = |x|


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Función de la cadena y = x^2
double chain_curve(double x) {
    return x * x;
}

// Derivada de la función dy/dx = 2x
double chain_deriv(double x) {
    return 2.0 * x;
}

// Densidad ρ(x) = |x|
double density(double x) {
    return abs(x);
}

// Integrando para longitud de arco: sqrt(1 + (dy/dx)^2)
double chain_arc_integrand(double x) {
    double dy_dx = chain_deriv(x);
    return sqrt(1.0 + dy_dx*dy_dx);
}

// Integrando para masa: ρ(x) * ds = |x| * sqrt(1 + (2x)^2)
double mass_integrand(double x) {
    return density(x) * chain_arc_integrand(x);
}

// Integrando para x-centroide: x * ρ(x) * ds
double x_centroid_integrand(double x) {
    return x * mass_integrand(x);
}

// Integrando para y-centroide: y(x) * ρ(x) * ds
double y_centroid_integrand(double x) {
    return chain_curve(x) * mass_integrand(x);
}

// Método de Simpson mejorado (para manejar singularidad en x=0)
double improved_simpson(double a, double b, double (*f)(double), int n = 1000) {
    // Partición simétrica para manejar mejor la singularidad
    if (a * b < 0) { // Si el intervalo cruza x=0
        double left = simpson_integration(a, 0, f, n/2);
        double right = simpson_integration(0, b, f, n/2);
        return left + right;
    }
    return simpson_integration(a, b, f, n);
}

int main() {
    const double a = -1.0;
    const double b = 1.0;
    
    // 1. Longitud de arco
    double arc_length = improved_simpson(a, b, chain_arc_integrand);
    
    // 2. Masa total
    double total_mass = improved_simpson(a, b, mass_integrand);
    
    // 3. Centroide x̄
    double x_numerator = improved_simpson(a, b, x_centroid_integrand);
    double x_centroid = x_numerator / total_mass;
    
    // 4. Centroide ȳ
    double y_numerator = improved_simpson(a, b, y_centroid_integrand);
    double y_centroid = y_numerator / total_mass;
    
    cout << "Resultados para la cadena y = x^2 con densidad ρ(x) = |x|:" << endl;
    cout << "1. Longitud de arco: " << setprecision(12) << arc_length << endl;
    cout << "2. Masa total: " << total_mass << endl;
    cout << "3. Centroide x̄: " << x_centroid << endl;
    cout << "4. Centroide ȳ: " << y_centroid << endl;
    
    return 0;
}