#include <iostream>

#include "prime_utils.h"
long prueba (long number);

int main(int argc, char **argv){
    
    long number = std::stol(argv[1]);
    if(isprime(number)){
        std::cout<<"El factor primo mas grande menor o igual que " << number << " es: " << number << "\n";
    }else{ 
        std::cout<<"El factor primo mas grande menor o igual que " << number << " es: " << prueba(number) << "\n";
    }
    /*for(long ii=number; ii>1; ii--){
        if(isprime(ii) && number%ii==0){
            std::cout<<"El factor primo mas grande menor o igual que " << number << " es: " << ii << "\n";
            break;
        }
    }*/


    return 0;
}

long prueba (long number){

    long n;
    for(long ii=2; ii<number; ii++){
        if(isprime(ii)){
            n=ii;
        }

        while(number%n==0 && number/n!=1){
           number /= n;
        }
    }

    return number;
}
