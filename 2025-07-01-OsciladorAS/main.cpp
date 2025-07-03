#include <iostream>
#include <valarray>
#include <cmath>
#include <functional>
#include <fstream>
#include <iomanip>


typedef std::valarray<double> state_t; // alias for state type

void initial_conditions(state_t & y);
void fderiv(const state_t & y, state_t & dydt, double t, double omega);

template <class deriv_t, class system_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, double omega);

template <class deriv_t, class system_t>
void solve_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, double omega);

int main(int argc, char **argv)
{

    double delta = std::stod(argv[1]);
    double tinit = std::stod(argv[2]);
    double tend = std::stod(argv[3]);
    double omega = std::stod(argv[4]);

    const int N = 2; // Dos variables: x (posición) y v (velocidad)
    state_t y(N);
    initial_conditions(y);

    // Integrar con Euler
    integrate_euler(fderiv, y, tinit, tend, delta, omega);

    // Reiniciar condiciones iniciales para Heun
    initial_conditions(y);

    // Integrar con Heun
    solve_heun(fderiv, y, tinit, tend, delta, omega);

    return 0;
}

void initial_conditions(state_t & y)
{
    y[0] = 1.0; // Posición inicial (x0)
    y[1] = 0.0; // Velocidad inicial (v0)
}

void fderiv(const state_t & y, state_t & dydt, double t, double omega)
{
    dydt[0] = y[1];               // dx/dt = v
    dydt[1] = -omega * omega * y[0]; // dv/dt = -ω²x
}

template <class deriv_t, class system_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, double omega)
{
    system_t dsdt(s.size());

    const std::string nombreArchivo = "output-euler.txt";

    // Crear y abrir el archivo
    std::ofstream archivo(nombreArchivo);

    // Verificar si se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al crear el archivo: " << nombreArchivo << std::endl;
        return;
    }

    // Configurar formato científico con 5 decimales
    archivo << std::scientific << std::setprecision(5);

    for(double t = tinit; t <= tend; t += dt) {
        fderiv(s, dsdt, t, omega);
        s += dt * dsdt; 
        archivo << s[0] << "\t" << s[1] << std::endl;
    }

    archivo.close();
}

template <class deriv_t, class system_t>
void solve_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, double omega)
{
    // vector to store derivs
    system_t k1, k2;
    k1.resize(s.size());
    k2.resize(s.size());

    const std::string nombreArchivo = "output-heun.txt";

    // Crear y abrir el archivo
    std::ofstream archivo(nombreArchivo);

    // Verificar si se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al crear el archivo: " << nombreArchivo << std::endl;
        return;
    }

    // Configurar formato científico con 5 decimales
    archivo << std::scientific << std::setprecision(5);

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t, omega);
        fderiv(s + dt*k1, k2, t + dt, omega);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*(k1 + k2)/2; // Heun

        // write new state
        archivo << s[0] << "\t" << s[1] << std::endl;
      }

    archivo.close();
}