#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iomanip>

using namespace std;

/*Para calcular los momentos de la distribución Gamma, implementaré un método numérico robusto que 
combine cuadratura de Gauss y transformaciones adecuadas para manejar la cola de la distribución.
*/

// Función Gamma (aproximación simple)
double gamma_function(double x) {
    // Aproximación de Lanczos para mayor precisión
    const double g = 5.0;
    double coef[6] = {1.000000000190015, 76.18009172947146, -86.50532032941677,
                      24.01409824083091, -1.231739572450155, 0.1208650973866179e-2};
    
    double tmp = x + g + 0.5;
    double ser = 1.000000000190015;
    
    for (int j = 1; j <= 5; j++) {
        ser += coef[j] / (x + j);
    }
    
    return sqrt(2.0 * M_PI) * pow(tmp, x + 0.5) * exp(-tmp) * ser / x;
}

// PDF de la distribución Gamma
double gamma_pdf(double x, double alpha, double beta) {
    if (x <= 0.0) return 0.0;
    return (pow(beta, alpha) * pow(x, alpha - 1.0) * exp(-beta * x)) / gamma_function(alpha);
}

// Integrando para el cálculo de momentos (x^k * f(x))
double moment_integrand(double x, double alpha, double beta, int k) {
    return pow(x, k) * gamma_pdf(x, alpha, beta);
}

// Cuadratura de Gauss-Legendre para integral de 0 a infinito (con transformación)
double gauss_legendre_inf(double alpha, double beta, int k, int n = 32) {
    // Puntos y pesos para cuadratura de Gauss-Legendre
    const double xi[32] = {
        -0.9972638618494816, -0.9856115115452684, -0.9647622555875064, -0.9349060759377397,
        -0.8963211557660521, -0.8493676137325700, -0.7944837959679424, -0.7321821187402897,
        -0.6630442669302152, -0.5877157572407623, -0.5068999089322294, -0.4213512761306353,
        -0.3318686022821276, -0.2392873622521371, -0.1444719615827965, -0.0483076656877383,
         0.0483076656877383,  0.1444719615827965,  0.2392873622521371,  0.3318686022821276,
         0.4213512761306353,  0.5068999089322294,  0.5877157572407623,  0.6630442669302152,
         0.7321821187402897,  0.7944837959679424,  0.8493676137325700,  0.8963211557660521,
         0.9349060759377397,  0.9647622555875064,  0.9856115115452684,  0.9972638618494816
    };
    
    const double wi[32] = {
        0.0070186100094701, 0.0162743947309057, 0.0253920653092621, 0.0342738629130214,
        0.0428358980222267, 0.0509980592623762, 0.0586840934785355, 0.0658222227763618,
        0.0723457941088485, 0.0781938957870703, 0.0833119242269467, 0.0876520930044038,
        0.0911738786957639, 0.0938443990808046, 0.0956387200792749, 0.0965400885147278,
        0.0965400885147278, 0.0956387200792749, 0.0938443990808046, 0.0911738786957639,
        0.0876520930044038, 0.0833119242269467, 0.0781938957870703, 0.0723457941088485,
        0.0658222227763618, 0.0586840934785355, 0.0509980592623762, 0.0428358980222267,
        0.0342738629130214, 0.0253920653092621, 0.0162743947309057, 0.0070186100094701
    };
    
    // Transformación para mapear [-1,1] a [0,∞)
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double t = xi[i];
        double x = (1.0 + t) / (1.0 - t);  // Transformación t -> (1+t)/(1-t)
        double jacobian = 2.0 / ((1.0 - t) * (1.0 - t)); // Jacobiano de la transformación
        sum += wi[i] * moment_integrand(x, alpha, beta, k) * jacobian;
    }
    
    return sum;
}

int main() {
    const double alpha = 2.5;  // Parámetro alpha de la distribución Gamma
    const double beta = 1.5;   // Parámetro beta de la distribución Gamma
    const int max_moment = 10; // Número de momentos a calcular
    
    cout << "Momentos de la distribución Gamma (α=" << alpha << ", β=" << beta << ")" << endl;
    cout << "----------------------------------------" << endl;
    cout << setw(5) << "k" << setw(25) << "Momento <x^k>" << endl;
    
    for (int k = 0; k <= max_moment; k++) {
        double moment = gauss_legendre_inf(alpha, beta, k);
        cout << setw(5) << k << setw(25) << scientific << setprecision(12) << moment << endl;
        
        // Verificación con fórmula teórica para los primeros momentos
        if (k == 0 && abs(moment - 1.0) > 1e-6) {
            cerr << "Error: El momento 0 debería ser 1 (normalización)" << endl;
        }
        if (k == 1 && abs(moment - alpha/beta) > 1e-6) {
            cerr << "Error en momento 1: Valor esperado " << alpha/beta << ", obtenido " << moment << endl;
        }
    }
    
    return 0;
}