#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Función Gamma (aproximación simple para valores enteros y semi-enteros)
double gamma_function(double alpha) {
    if (alpha == 1.0) return 1.0;
    if (alpha == 1.5) return 0.5 * std::sqrt(M_PI);
    return (alpha - 1.0) * gamma_function(alpha - 1.0);
}

// PDF de la distribución Gamma
double gamma_pdf(double x, double alpha, double beta) {
    if (x <= 0.0) return 0.0;
    return (pow(x, alpha - 1.0) * exp(-x / beta)) / (pow(beta, alpha) * gamma_function(alpha);
}

// Método de Simpson para integrar la PDF desde 0 hasta x
double simpson_cdf(double x, double alpha, double beta, int n = 1000) {
    if (x <= 0.0) return 0.0;
    
    double h = x / n;
    double sum = gamma_pdf(0.0, alpha, beta) + gamma_pdf(x, alpha, beta);
    
    for (int i = 1; i < n; i++) {
        double xi = i * h;
        if (i % 2 == 0) {
            sum += 2.0 * gamma_pdf(xi, alpha, beta);
        } else {
            sum += 4.0 * gamma_pdf(xi, alpha, beta);
        }
    }
    
    return sum * h / 3.0;
}

// Cuadratura de Gauss con 7 puntos
double gauss_quadrature_cdf(double x, double alpha, double beta) {
    // Puntos y pesos para cuadratura de Gauss-Legendre de 7 puntos en [-1, 1]
    const int n = 7;
    const double xi[n] = {
        0.0,
        -0.405845151377397, 0.405845151377397,
        -0.741531185599394, 0.741531185599394,
        -0.949107912342759, 0.949107912342759
    };
    const double wi[n] = {
        0.417959183673469,
        0.381830050505119, 0.381830050505119,
        0.279705391489277, 0.279705391489277,
        0.129484966168870, 0.129484966168870
    };
    
    if (x <= 0.0) return 0.0;
    
    // Transformación del intervalo [0, x] a [-1, 1]
    double a = 0.0, b = x;
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        double t = ((b - a) * xi[i] + (b + a)) / 2.0;
        sum += wi[i] * gamma_pdf(t, alpha, beta);
    }
    
    return sum * (b - a) / 2.0;
}

int main() {
    const double alpha = 7.5;
    const double beta = 1.0;
    const double x_min = 0.0;
    const double x_max = 20.0;
    const int steps = 200;
    
    ofstream outfile("gamma_cdf.csv");
    outfile << "x,Simpson,Gauss" << endl;
    
    for (int i = 0; i <= steps; i++) {
        double x = x_min + i * (x_max - x_min) / steps;
        double cdf_simpson = simpson_cdf(x, alpha, beta);
        double cdf_gauss = gauss_quadrature_cdf(x, alpha, beta);
        
        outfile << fixed << setprecision(6) << x << "," 
                << cdf_simpson << "," << cdf_gauss << endl;
    }
    
    outfile.close();
    cout << "Datos guardados en gamma_cdf.csv" << endl;
    
    return 0;
}


/*import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('gamma_cdf.csv')
plt.figure(figsize=(10, 6))
plt.plot(data['x'], data['Simpson'], label='Simpson')
plt.plot(data['x'], data['Gauss'], '--', label='Gauss Quadrature')
plt.title('CDF de la Distribución Gamma (α=7.5, β=1.0)')
plt.xlabel('x')
plt.ylabel('F(x)')
plt.legend()
plt.grid(True)
plt.show()*/
