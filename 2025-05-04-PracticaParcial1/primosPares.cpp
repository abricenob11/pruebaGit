#include <iostream>
#include <fstream>

#include <cmath>

bool isprime(long n);
double nth_twin_primes(int n);

int main(void){

    /*nth_twin_primes(1);
    nth_twin_primes(2);
    nth_twin_primes(10);
    nth_twin_primes(5098);*/

    std::ofstream file("PrimosPares.txt");
    for(int ii=1; ii<=100; ii++){
        file << ii << " " << nth_twin_primes(ii) << std::endl;
    }

    file.close();

    return 0;
}

bool isprime(long n) {
    for(long ii=2; ii*ii<=n; ii++)
        if(n%ii==0) return false;
        
    return true;
}


void nth_twin_primes(int n){
    int contador=0;
    int primo=2;
    while(contador<n){
        primo++;
        if(isprime(primo)&&isprime(primo+2)){
            contador++;
        }
    }
    std::cout << "La " << n <<"th pareja de numeros primos es (" << primo << ", " << primo+2 <<") \n";
    
}

return sqrt(pow(primo, 2) + pow(primo+2, 2));