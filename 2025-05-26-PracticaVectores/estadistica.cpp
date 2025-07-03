#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <numeric>
#include <algorithm>

void lecv(std::vector <double> &x);
double mean(const std::vector <double> &x);
double median(std::vector <double> &x);


int main(int argc, char **argv){

    std::vector <double> x;

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    lecv(x);
    std::cout << "Mostrando el vector " << std::endl;
    for(auto val : x){
        std::cout << val << std::endl;
    }

    std::cout << "La media del vector es: " << std::endl;
    std::cout << mean(x) << std::endl;
    std::cout << "La mediana del vector es: " << std::endl;
    std::cout << median(x) << std::endl;

    std::cout << "Mostrando el vector " << std::endl;
    for(auto val : x){
        std::cout << val << std::endl;
    }

    return 0;
}

void lecv(std::vector <double> &x){
    std::string fname = "datos.txt";
    double m;
    std::ifstream fin(fname);

    if (!fin.is_open()) {
        std::cerr << "Error al abrir el archivo: " << fname << std::endl;
    }

    while(fin >> m){
        x.push_back(m);
    }

    fin.close();
}

double mean(const std::vector <double> &x){
    return std::accumulate(x.begin(), x.end(), 0.0) / x.size();
}

double median(std::vector <double> &x){
    double guardar;
    std::sort(x.begin(), x.end()); //para ordenar el vector
    /*for(int ii=0; ii<x.size()-1; ii++){
        for(int jj=ii+1; jj<x.size(); jj++){
            if(x[jj] < x[ii]){
                guardar = x[jj];
                x[jj] = x[ii];
                x[ii] = guardar;
            }
        }
    }*/


    if(x.size()%2==0){
        return (x[x.size()/2-1] + x[x.size()/2]) / 2;
    } else {
        return x[x.size()/2];
    }
}

