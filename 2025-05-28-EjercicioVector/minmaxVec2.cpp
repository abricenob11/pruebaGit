#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


//g++ -std=c++17 -fsanitize=undefined,leak,address
double minv(const std::vector<double> &v);
double maxv(const std::vector<double> &v);
int indMin(const std::vector<double> &v);
int indMax(const std::vector<double> &v);


int main(void){

    std::vector<double> v (10, 0); 
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Distribución uniforme entre 0.0 y 1.0
    std::uniform_real_distribution<double> distrib(0.0, 1.0);

    for (int i = 0; i < 10; ++i) {
        v[i] = distrib(gen);
    }

    for(auto val : v){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "el minimo valor es: " << minv(v) << std::endl;
    std::cout << "el maximo valor es: " << maxv(v) << std::endl;
    std::cout << "el indice del menor valor es: " << indMin(v) << std::endl;
    std::cout << "el indice del maximo valor es: " << indMax(v) << std::endl;


    return 0;
}

double minv(const std::vector<double> &v){
    if(v.empty()) return 0; // Manejo de vector vacío
    return *std::min_element(v.begin(), v.end());
}

double maxv(const std::vector<double> &v){
    return *std::max_element(v.begin(), v.end());
}

int indMin(const std::vector<double> &v){
    return std::distance(v.begin(), std::min_element(v.begin(), v.end()));

}

int indMax(const std::vector<double> &v){
    return std::distance(v.begin(), std::max_element(v.begin(), v.end()));

}
