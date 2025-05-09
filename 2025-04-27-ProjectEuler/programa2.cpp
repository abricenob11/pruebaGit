#include <iostream>
#include <cmath>

bool isprime(long n);
long largest_factor (long number);

int main(int argc, char **argv){
    
    long number = std::stol(argv[1]);
    if(isprime(number)){
        std::cout<<"El factor primo mas grande menor o igual que " << number << " es: " << number << "\n";
    }else{ 
        std::cout<<"El factor primo mas grande menor o igual que " << number << " es: " << largest_factor(number) << "\n";
    }

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

long largest_factor (long number){
    long n;
    int contador=0;
    do{ 
        for(long ii=2; ii<number; ii++){
            if(isprime(ii)){
                n=ii;
            }
            while(number%n==0 && number/n!=1){
            number /= n;
            }
        }
    contador++;
    }while(contador<2)
    return number;
}
