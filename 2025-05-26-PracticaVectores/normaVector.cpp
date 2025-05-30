#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>




int main(){

    std::vector<double> data1 (3, 0.0);

    auto fill2 = [](std::vector<double> & data1){
        for(double ii =0.0; ii<data1.size(); ii++){
        data1[ii] = ii;
        }
    };
    
    fill2(data1);

    auto show = [](double &val){std::cout << val << std::endl;};
    std::for_each(data1.begin(), data1.end(), show);

    auto cuadrado = [](double &val){val *= val;};
    std::for_each(data1.begin(), data1.end(), cuadrado);
    double sum = 0.0;

    for(auto val : data1){
        sum += val;
    }

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << "norma vector " << std::sqrt(sum) << std::endl;


    return 0;
}

