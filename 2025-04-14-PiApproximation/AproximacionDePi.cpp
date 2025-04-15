#include <iostream>
#include <cmath>

double pi_aprox(int n);

int main (void){
    
    std::cout<<"valor de pi es " << M_PI << "\n";

    for(int i=1; i<=20; i++){ 
        std::cout<<"Para n: " << i << " pi es igual a: " << pi_aprox(i) << " y la diferencia relativa con el valor real de pi es: " 
            << abs(1.0-(pi_aprox(i)/M_PI)) <<"\n"; 
    }
    
    return 0;
}


double pi_aprox(int n){
    double pi=0;
    for(int i=0; i<=n; i++){
        pi += (1.0/std::pow(16, i)) * (
            (4.0 / (8*i+1)) - 
            (2.0 / (8*i+4)) -
            (1.0 / (8*i+5)) -
            (1.0 / (8*i+6)));
    }

    return pi;
}