#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>



int dotProduct (const std::vector<int> &v1, const std::vector<int> &v2);

int main(){

    std::vector<int> data1 {0, 1, 2, 3, 4};
    std::vector<int> data2 {5, 4, 2, 3, 1};
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    std::cout << "producto punto " << dotProduct(data1, data2) << std::endl;
    return 0;
}


int dotProduct (const std::vector<int> &v1, const std::vector<int> &v2){
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
}


