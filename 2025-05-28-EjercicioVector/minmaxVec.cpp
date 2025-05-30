#include <iostream>
#include <vector>
#include <random>


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
    double min = v[0];
    for(auto val : v){
        if(val < min){
            min = val;
        }
    }

    return min;
}

double maxv(const std::vector<double> &v){
    double max = v[0];
    for(auto val : v){
        if(val > max){
            max = val;
        }
    }

    return max;
}

int indMin(const std::vector<double> &v){
    double min = v[0];
    int indiceMenor=0;
    for(int ii=0; ii < v.size(); ii++){
        if(v[ii] < min){
            min = v[ii];
            indiceMenor = ii;
        }
    }

    return indiceMenor;
}

int indMax(const std::vector<double> &v){
    double max = v[0];
    int indiceMayor=0;
    for(int ii=0; ii < v.size(); ii++){
        if(v[ii] > max){
            max = v[ii];
            indiceMayor = ii;
        }
    }

    return indiceMayor;
}
