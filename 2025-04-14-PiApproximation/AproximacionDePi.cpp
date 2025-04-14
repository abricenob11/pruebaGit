#include <iostream>
#include <cmath>

double pi_aprox(int n);

int main (void){
    
    
    
    return 0;
}


double pi_aprox(int n){
    double pi=0;
    for(int i=0; i<=n; i++){
        pi += (1/std::pow(16, i))[(4/8*i+1)-(2/8*i+4)-(1/8*i+5)-(1/8*i+6)]
    }


    return pi;
}