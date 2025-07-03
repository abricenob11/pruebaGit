#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;
/*Para implementar la función di-logaritmo y graficarla en el intervalo (0, 1.0) con alta precisión, 
usaré el método de Simpson adaptativo que garantice un error menor a 10⁻⁶. 
También consideraré las singularidades en los extremos del intervalo.*/



// Integrand para la función di-logaritmo
double di_log_integrand(double t) {
    if (t == 0.0) return 0.0; // límite cuando t→0
    if (t == 1.0) return numeric_limits<double>::infinity(); // singularidad
    return -log(1.0 - t) / t;
}

// Método de Simpson adaptativo con control de error
double adaptive_simpson(double a, double b, double (*f)(double), double tol = 1e-6, int max_depth = 20) {
    double h = b - a;
    double c = (a + b) / 2.0;
    
    double fa = f(a);
    double fb = f(b);
    double fc = f(c);
    
    double S = (h / 6.0) * (fa + 4.0 * fc + fb);
    
    return adaptive_simpson_rec(a, b, f, tol, S, fa, fb, fc, max_depth);
}

double adaptive_simpson_rec(double a, double b, double (*f)(double), double tol, double S, 
                          double fa, double fb, double fc, int depth) {
    double c = (a + b) / 2.0;
    double h = b - a;
    
    double d = (a + c) / 2.0;
    double e = (c + b) / 2.0;
    
    double fd = f(d);
    double fe = f(e);
    
    double S1 = (h / 12.0) * (fa + 4.0 * fd + fc);
    double S2 = (h / 12.0) * (fc + 4.0 * fe + fb);
    double S_total = S1 + S2;
    
    if (depth <= 0 || fabs(S_total - S) <= 15.0 * tol) {
        return S_total + (S_total - S) / 15.0;
    }
    
    return adaptive_simpson_rec(a, c, f, tol/2.0, S1, fa, fc, fd, depth - 1) +
           adaptive_simpson_rec(c, b, f, tol/2.0, S2, fc, fb, fe, depth - 1);
}

// Función di-logaritmo principal
double di_logarithm(double x) {
    if (x <= 0.0) return 0.0;
    if (x >= 1.0) return M_PI*M_PI/6.0; // Li₂(1) = ζ(2) = π²/6
    
    // Para x cercano a 1, es mejor transformar la variable
    if (x > 0.9) {
        return M_PI*M_PI/6.0 - di_logarithm(1.0 - x) - log(x)*log(1.0 - x);
    }
    
    return adaptive_simpson(0.0, x, di_log_integrand);
}

int main() {
    const double x_min = 0.001; // Evitamos x=0 por la singularidad
    const double x_max = 0.999; // Evitamos x=1 por la singularidad
    const int steps = 200;
    
    ofstream outfile("di_logarithm.csv");
    outfile << "x,Li2(x)" << endl;
    
    for (int i = 0; i <= steps; i++) {
        double x = x_min + i * (x_max - x_min) / steps;
        double li2 = di_logarithm(x);
        
        outfile << fixed << setprecision(10) << x << "," 
                << scientific << setprecision(12) << li2 << endl;
    }
    
    outfile.close();
    cout << "Datos guardados en di_logarithm.csv" << endl;
    
    return 0;
}

/*import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv('di_logarithm.csv')
plt.figure(figsize=(10, 6))
plt.plot(data['x'], data['Li2(x)'], label='Li₂(x)')
plt.title('Función Di-Logaritmo (Dilogarithm)')
plt.xlabel('x')
plt.ylabel('Li₂(x)')
plt.grid(True)
plt.legend()
plt.show()

# Comparación con valores conocidos
print("Li₂(0.5) calculado:", data[data['x'] == 0.5]['Li2(x)'].values[0])
print("Li₂(0.5) exacto:", np.pi**2/12 - (np.log(2)**2)/2)*/