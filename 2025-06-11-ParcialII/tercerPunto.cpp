#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <random>


void print(std::string msg, const std::valarray<double>& v)
{
    std::cout << msg << " ";
    for (auto n: v) { std::cout << " " << n; }
    std::cout << '\n';
}

double mean_field(int N, int seed){
    std::valarray<double> x (N);
    std::valarray<double> y (N);

    for(auto &val: x){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> distrib(-0.5, 5.0);
        val = distrib(gen);
    }

    for(auto &val: y){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> distrib(-0.5, 5.0);
        val = distrib(gen);
    }

    
    std::valarray<double> vx = std::pow(x, 2) - std::pow(y, 2);
    std::valarray<double> vy =2*x*y;

    std::valarray<double> norma = std::sqrt(std::pow(vx, 2) + std::pow(vy, 2));

    return norma.sum() / norma.size();

}


int main(void){
    std::cout << mean_field(20, 10)<< std::endl;
    
}





