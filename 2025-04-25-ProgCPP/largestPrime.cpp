#include <iostream>

#include "prime_utils.h"

int main(int argc, char **argv){
    
    int number = std::stoi(argv[1]);
    for(int ii=number-1; ii>0; ii--){
        if(isprime(ii) && number%ii==0){
            std::cout<<"El factor primo menor que " << number << " es: " << ii << "\n";
            break;
        }
    }


    return 0;
}
