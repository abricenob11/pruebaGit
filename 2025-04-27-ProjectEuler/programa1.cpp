#include <iostream>
#include <cmath>

bool isprime(long n);

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

bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    // suppose it is prime
    bool flag = true; 

    if (n == 2) {
        return true;
    }

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }

    return flag;
}
