#include <iostream>
#include <valarray>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;


//Implementaré una simulación de partícula bajo gravedad usando el método de Euler, 
//luego añadiré amortiguamiento e interacción con el suelo, todo utilizando valarray para representar los vectores.


const double g = 9.81; // Aceleración gravitacional
const double m = 0.987; // Masa de la partícula
const double dt = 0.01; // Paso de tiempo
const int steps = 1000; // Número de pasos de simulación

// Función para graficar datos
void plotData(const valarray<double>& time, 
              const valarray<double>& x,
              const valarray<double>& y,
              const valarray<double>& z,
              const string& filename) {
    ofstream outfile(filename);
    outfile << "Time,X,Y,Z" << endl;
    for (size_t i = 0; i < time.size(); ++i) {
        outfile << fixed << setprecision(4) 
                << time[i] << "," 
                << x[i] << "," 
                << y[i] << "," 
                << z[i] << endl;
    }
    outfile.close();
}

int main() {
    // 1. Condiciones iniciales
    valarray<double> R = {0.0, 0.0, 4.3}; // Posición inicial (x,y,z)
    valarray<double> V = {0.123, 0.0, 0.98}; // Velocidad inicial (vx,vy,vz)
    
    // Arrays para almacenar la trayectoria
    valarray<double> time(steps);
    valarray<double> x_pos(steps), y_pos(steps), z_pos(steps);
    
    // 2. Simulación sin amortiguamiento
    for (int i = 0; i < steps; ++i) {
        time[i] = i * dt;
        x_pos[i] = R[0];
        y_pos[i] = R[1];
        z_pos[i] = R[2];
        
        // Fuerza: solo gravedad en z (0, 0, -mg)
        valarray<double> F = {0.0, 0.0, -m * g};
        
        // Método de Euler
        R += dt * V;
        V += dt * F / m;
    }
    
    plotData(time, x_pos, y_pos, z_pos, "trajectory_no_damping.csv");
    
    // 3. Reiniciar para simulación con amortiguamiento
    R = {0.0, 0.0, 4.3};
    V = {0.123, 0.0, 0.98};
    const double damping = 0.1; // Coeficiente de amortiguamiento
    
    for (int i = 0; i < steps; ++i) {
        time[i] = i * dt;
        x_pos[i] = R[0];
        y_pos[i] = R[1];
        z_pos[i] = R[2];
        
        // Fuerza: gravedad + amortiguamiento (-damping*V)
        valarray<double> F = {0.0, 0.0, -m * g} - damping * V;
        
        // Método de Euler
        R += dt * V;
        V += dt * F / m;
    }
    
    plotData(time, x_pos, y_pos, z_pos, "trajectory_damping.csv");
    
    // 4. Reiniciar para simulación con suelo
    R = {0.0, 0.0, 4.3};
    V = {0.123, 0.0, 0.98};
    const double ground_level = 0.0;
    const double k = 100.0; // Constante elástica del suelo
    
    for (int i = 0; i < steps; ++i) {
        time[i] = i * dt;
        x_pos[i] = R[0];
        y_pos[i] = R[1];
        z_pos[i] = R[2];
        
        // Fuerza: gravedad + amortiguamiento + fuerza del suelo si z < 0
        valarray<double> F = {0.0, 0.0, -m * g} - damping * V;
        
        if (R[2] < ground_level) {
            F[2] += -k * R[2]; // Fuerza elástica del suelo
            F[2] -= 0.5 * V[2] * abs(V[2]); // Resistencia no lineal del suelo
        }
        
        // Método de Euler
        R += dt * V;
        V += dt * F / m;
        
        // Corrección para evitar penetración en el suelo
        if (R[2] < ground_level) {
            R[2] = ground_level;
            V[2] = -0.6 * V[2]; // Coeficiente de restitución
        }
    }
    
    plotData(time, x_pos, y_pos, z_pos, "trajectory_ground.csv");
    
    cout << "Simulaciones completadas. Datos guardados en:\n"
         << "1. trajectory_no_damping.csv (solo gravedad)\n"
         << "2. trajectory_damping.csv (con amortiguamiento)\n"
         << "3. trajectory_ground.csv (con suelo interactivo)" << endl;
    
    return 0;
}

/*import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Cargar datos
data_no_damp = pd.read_csv('trajectory_no_damping.csv')
data_damp = pd.read_csv('trajectory_damping.csv')
data_ground = pd.read_csv('trajectory_ground.csv')

# Crear figura 3D
fig = plt.figure(figsize=(15, 5))

# 1. Sin amortiguamiento
ax1 = fig.add_subplot(131, projection='3d')
ax1.plot(data_no_damp['X'], data_no_damp['Y'], data_no_damp['Z'])
ax1.set_title('Solo gravedad')

# 2. Con amortiguamiento
ax2 = fig.add_subplot(132, projection='3d')
ax2.plot(data_damp['X'], data_damp['Y'], data_damp['Z'])
ax2.set_title('Con amortiguamiento')

# 3. Con suelo
ax3 = fig.add_subplot(133, projection='3d')
ax3.plot(data_ground['X'], data_ground['Y'], data_ground['Z'])
ax3.set_title('Con interacción con el suelo')

plt.tight_layout()
plt.show() */