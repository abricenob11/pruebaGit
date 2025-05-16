#pragma once
#include <functional>
#include <cmath>

using fptr = std::function<double(double)>;

double trapezoid(double a, double b, int n, fptr fun);
double simpson(double a, double b, int N, fptr fun);

using algptr = std::function<double(double, double, int, fptr)>;

double richardson(double a, double b, fptr f, int N,  algptr alg, int alpha);

double gauss2(double a, double b, fptr fun);

double gauss3(double a, double b, double c, fptr fun);

double gauss7(double a, double b, fptr fun);
