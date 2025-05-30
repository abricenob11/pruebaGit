#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>


//g++ -std=c++17 -fsanitize=undefined,leak,address

void derivada (const std::vector <double> &coe, std::vector<double> &deriv);
double eval(const std::vector <double> &coe, double x);

int main(void){

    std::vector<double> coe = {1 , 3, 4.5}; // 1*x^0 + 3*x^1 + 4.5*x^2
    std::vector<double> deriv; // {3, 9}
    deriv.resize(coe.size()-1, 0);

    derivada(coe, deriv);
    std::cout << "Coeficientes" << std::endl;
    for(auto val : coe){
        std::cout << val << " ";
    }

    std::cout << "\nDerivada" << std::endl;
    auto impr = [](double val){std::cout << val << " ";};
    std::for_each(deriv.begin(), deriv.end(), impr);
    std::cout << std::endl;

    for(int ii=0; ii<coe.size(); ii++){
        std::cout << coe[ii] << "x^" << ii;
        if(ii<coe.size()-1){std::cout << " + ";}
    }
    std::cout << ": " << eval(coe, 3.0) << std::endl;

    std::ofstream file("datosPolinomio.txt");

        for(double ii=-10; ii <= 10; ii +=0.1){
            file << ii << " " << eval(coe, ii) << std::endl;
        }

    file.close();

    std::ofstream file2("datosDerivada.txt");

        for(double ii=-10; ii <= 10; ii +=0.1){
            file2 << ii << " " << eval(deriv, ii) << std::endl;
        }

    file2.close();

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    return 0;
}


void derivada (const std::vector <double> &coe, std::vector<double> &deriv){
    
    //deriv[0] = coe[1] * 1
    //deriv[1] = coe[2] * 2

    for(int ii = 0; ii < deriv.size(); ii++){
        deriv[ii] = coe[ii+1] * (ii+1);
    }    

}

double eval(const std::vector <double> &coe, double x){
    // 1*x^0 + 3*x^1 + 4.5*x^2
    //coe[0]*std::pow(x, 0) + coe[1]*std::pow(x, 1) + coe[2]*std::pow(x, 2)
    double suma = 0.0;
    for(int ii=0; ii < coe.size(); ii++){
        suma += coe[ii]*std::pow(x, ii);
    }

    return suma;
}
