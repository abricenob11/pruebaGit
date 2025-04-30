#include <iostream>

#include "prime_utils.h"

int main (int argc, char **argv){
    long suma=0;
    long number = std::stol(argv[1]);
    for(long ii=number; ii>1; ii--){
        if(isprime(ii)){
            suma +=ii;
        }
    }
    std::cout<<"La suma de los numeros primos menores o iguales a "<<number<<" es: "<<suma<< "\n";
    return 0;
}