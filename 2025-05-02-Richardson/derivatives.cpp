#include "derivatives.h"

double forward_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x)) / h;
}
double central_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x - h)) / (2*h);
}

double richardson(double x, double h, fptr f, algptr alg, int alpha)
{
    double aux = std::pow(2.0, alpha);
    double v1 = alg(x, h, f);
    double v2= alg(x, h/2.0, f);
    return(aux*v2 - v1)/(aux-1.0);
}