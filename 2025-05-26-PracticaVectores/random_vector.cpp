#include "random_vector.h"

void fill_randomly(std::vector<double> &data){
    // Crear un generador de números aleatorios
    std::random_device rd;  // Dispositivo aleatorio (semilla)
    std::mt19937 gen(rd()); // Motor de generación Mersenne Twister

    // Definir el rango (ejemplo: entre 1 y 100)
    std::uniform_int_distribution<int> distrib(1, 10);

    // Generar 10 números aleatorios
    for (int ii = 0; ii < data.size(); ++ii) {
        data[ii] = distrib(gen);
    }
}


void print(const std::vector<double> &data, std::string &fname){
    
    fname = "numerosRandom.txt";
    std::ofstream fin(fname);

    if (!fin.is_open()) {
        std::cerr << "Error al crear el archivo: " << fname << std::endl;
    }

    fin << std::scientific << std::setprecision(5);

    for(auto val : data){ 
        fin << val << std::endl;
    }

    fin.close();
}

void printRandom(std::vector<double> &data){

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(data.begin(), data.end(), g);
}