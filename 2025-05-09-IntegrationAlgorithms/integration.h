#pragma once
#include <functional>

using fptr = std::function<double(double)>;

double trapezoid(double a, double b, int n, fptr fun);