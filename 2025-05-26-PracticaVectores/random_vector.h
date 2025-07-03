#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>

void fill_randomly(std::vector<double> &data);

void print(const std::vector<double> &data, std::string &fname);
void printRandom(std::vector<double> &data);

/*
#include <iostream>
#include <array>
#include <algorithm>
void fill(std::array<double, 10> & data1);
int main(){
std::array<double, 10> data1;
//fill(data1);

auto fill2 = [](std::array<double, 10> & data1){
    for(double ii =0.0; ii<sizeof(data1)/sizeof(data1[0]); ii++){
    data1[ii] = ii;
    }
};

fill2(data1);

auto show = [](double &val){std::cout << val << std::endl;};
std::for_each(data1.begin(), data1.end(), show);


return 0;

}
void fill(std::array<double, 10> & data1){
double cont = 0.0;
for(auto &val : data1){
    val = cont;
    cont++;
}

/*for(double ii = 0.0; ii<sizeof(data1)/sizeof(data1[0]); ii++){
    data1[ii] = ii;
}*/

}
*/