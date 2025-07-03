#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

int main(int argc , char **argv)
{
    // declare the vector
    std::vector<double> data; 

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    // resize the vector
    std::cout << "Pidiendo memoria ...\n";
    data.resize(N, 0);


    //[&] para capturar todo por referencia
    //[=] para capturar todo por copia
    //[&a, &b] para capturar a y b por referencia
    //[a, b] para capturar a y b por copia
    //[&, b] para capturar todo por referencia menos b por copia

    auto print = [](double x){ std::cout << x << "\n"; };
    //std::for_each(data.begin(), data.end(), print);

    // initialize the data
    std::cout << "Iniciando datos ...\n";
    //fill(data);
    int ii = 0;
    auto fill = [&ii](double & x){ x = ii; ii++;};
    std::for_each(data.begin(), data.end(), fill);
    //std::for_each(data.begin(), data.end(), print);

    // compute the average
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << std::accumulate(data.begin(), data.end(), 0.0)/data.size() 
              << "\n";

    return 0;
}