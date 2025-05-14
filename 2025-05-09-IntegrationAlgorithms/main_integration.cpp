#include <iostream>
#include <fstream>
#include "integration.h"
#include <cmath>


double fun(double x);

int main(int argc, char **argv){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double exact_result {1.56898093601156};

    double a = -5.0;
    double b = 5.0;

    std::ofstream file("errores.txt");

    file.precision(15);
    file.setf(std::ios::scientific);

    for(int N=2; N<=2000000; N*=2){
        double trapecio = trapezoid(a, b, N, fun);
        double simp = simpson(a, b, N, fun);
        double richardson_tra = richardson(a, b, fun, N, trapezoid, 2);
        double richardson_simp = richardson(a, b, fun, N, simpson, 4);
        double error_tra = std::abs(1.0 - trapecio/exact_result);
        double error_simp = std::abs(1.0 - simp/exact_result);
        double error_richardson_tra = std::abs(1.0 - richardson_tra/exact_result);
        double error_richardson_simp = std::abs(1.0 - richardson_simp/exact_result);
        file << N << " "
                << error_tra << " "
                << error_simp << " "
                << error_richardson_tra << " "
                << error_richardson_simp << " "
                << std::endl;
    }

    file.close();

    return 0;
}

double fun(double x){
    return std::sin(std::pow(std::exp(1.0), x));
}
