#pragma once

// ivp_solver.h
#include <iostream>
#include <valarray>
#include <functional>


// function template to work with "any" type
template <class deriv_t, class system_t, class printer_t>//por usar templates no se escribe el otro cpp
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t dsdt(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*dsdt; // Euler

        // write new state
        writer(s, t);
      }
}

// function template to work with "any" type
template <class deriv_t, class system_t, class printer_t>
void integrate_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t k1, k2;
    k1.resize(s.size());
    k2.resize(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t);
        fderiv(s + dt*k1, k2, t + dt);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*(k1 + k2)/2; // Heun

        // write new state
        writer(s, t);
      }
}

template <class deriv_t, class system_t, class printer_t>
void integrate_RK(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t k1, k2, k3, k4;
    k1.resize(s.size());
    k2.resize(s.size());
    k3.resize(s.size());
    k4.resize(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t);
        fderiv(s + dt*k1/2, k2, t + (dt/2));
        fderiv(s + dt*k2/2, k3, t + (dt/2));
        fderiv(s + dt*k3, k4, t + dt);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*(k1 + 2*k2 + 2*k3 + k4)/6; // Heun

        // write new state
        writer(s, t);
      }
}