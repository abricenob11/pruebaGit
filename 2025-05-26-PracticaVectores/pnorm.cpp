#include <iostream>
#include <vector>
#include <cmath>


double pnorm(int p, const std::vector <double> &x);

int main(int argc, char **argv){

    std::vector <double> x {1, 2, 3, 4, 5};

    int p = std::stoi(argv[1]);

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << pnorm(p, x) << std::endl;

    return 0;
}

double pnorm(int p, const std::vector <double> &x){
    double sum = 0.0;
    for(int ii=0; ii<x.size(); ii++){
        sum += std::pow(x[ii], p);
    }

    return std::pow(sum, 1.0/p);
    
}