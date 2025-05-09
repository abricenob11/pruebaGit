#include "integration.h"

double trapezoid(double a, double b, int n, fptr fun){

    double intervalo = (b-a)/n;
    double v1 = fun(a);
    double v2 = fun(b);
    double sum=0.0;

    for(int k= 1; k<=n-1; k++){
        double xk = a+(k*intervalo);
        sum += fun(xk);
    }

    return intervalo*((v1/2) + sum + (v2/2));
}