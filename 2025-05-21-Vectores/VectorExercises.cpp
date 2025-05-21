#include <iostream>
#include <vector>
#include <string>

void fill(std::vector<double> & data1);
double suma(const std::vector<double> & data1);

int main(int argc, char **argv){
    
    int tamano = std::stoi(argv[1]); 
    std::vector<double> data1(tamano, 0);

    fill(data1);
    double avg = suma(data1);

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    std::cout<< "Promedio "<< avg << std::endl;

    return 0;
}

void fill(std::vector<double> & data1){
    for(int ii=0; ii<data1.size(); ii++){
        data1[ii] = ii;
    }
}
double suma(const std::vector<double> & data1){
    double suma = 0.0;
    for(int ii=0; ii<data1.size(); ii++){
        suma += data1[ii];
    }
    return suma / data1.size();
}
