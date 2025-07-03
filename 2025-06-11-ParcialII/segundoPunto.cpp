#include <iostream>
#include <cmath>
#include <array>


int main(int argc, char **argv){
    
    //std::cout << std::assoc_laguerre(1, 10, 0.5) << '\n';
    //std::vector<int> numbers;
    /*numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers[3]=4;

    for(auto val: numbers){
        std::cout << val << std::endl;
    }
    
    //std::cout<<numbers[3]<< std::endl;
    std::cout<<numbers.at(2)<< std::endl;
    }*/

    int arr[] = {1, 2, 3, 4, 5};
    std::array <int, 5>  a = {1, 2, 3, 4, 5};

    std::cout<<a.size()<< std::endl;


    return 0;
}