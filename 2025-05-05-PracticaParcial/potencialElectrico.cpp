#include <iostream>
#include <fstream>
#include <cmath>

double potencial(double x);
double dev_central(double x, double h);
double dev_central_richardson(double x, double h);
double electricfield(double x, double h);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double h = 0.02;

    // open file for writing
    std::ofstream file("derivatives.txt");

    file.precision(15);
    file.setf(std::ios::scientific);

    for(double ii=0; ii<=2.5; ii+=0.02){
        double exact_result = (-1) * electricfield(ii, 0.0);
        double r_c_result = (-1) * dev_central_richardson(ii, h);
        file << ii << " " << exact_result << " " << r_c_result << std::endl;
    }
}

double potencial(double x){
    return 2*x*std::sin(x);
}

double dev_central(double x, double h){
    double v1=potencial(x+h);
    double v2=potencial(x-h);
    return (v1-v2) / (2*h);
}

double dev_central_richardson(double x, double h){
    double v1=dev_central(x, h/2);
    double v2=dev_central(x, h);
    return (4*v1 - v2) / 3;
}

double electricfield(double x, double h){
    return (2*std::sin(x) + 2*x*std::cos(x));
}