#include <iostream>
#include <cmath>

#include "prime_utils.h"

int main(int argc, char **argv){
    long v1=2;
    long v2;
    int contador=1;
    for(long ii=3; ii>1; ii++){
        if(isprime(ii)){
            if(contador%2==0){
                v1=ii;
            }else{
                v2=ii;
            }
            std::cout<<"La diferencia entre " << v2 << " y " << v1 << " es: " << std::abs(v2-v1) << "\n";
            contador++;
        }
    }


    return 0;
}