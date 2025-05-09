#include <iostream>
#include <cmath>
#include <fstream>

long second_largest_prime_factor(long n);
void grafica(void);

int main(void){
    long v1 = second_largest_prime_factor(6);
    long v2 = second_largest_prime_factor(10); 
    long v3 = second_largest_prime_factor(18);
    long v4 = second_largest_prime_factor(334042800); 

    std::ofstream file("PrimosPares.txt");
    file << 6 << " " << v1 <<std::endl;
    file << 10 << " " << v2 <<std::endl;
    file << 18 << " " << v3 <<std::endl;
    file << 334042800 << " " << v4;

    file.close();

    return 0;
}


bool isprime(long n) {
    for(long ii=2; ii*ii<=n; ii++)
        if(n%ii==0) return false;
        
    return true;
}

long second_largest_prime_factor(long number){ 
    int contador=0;
    for(long ii=number; ii>=2; ii--){
        if(isprime(ii) && number%ii==0){
            contador++;
            if(contador==2) return ii;
        }
    }
    return number;
}

void grafica(void){
    long v1 = second_largest_prime_factor(6);
    long v2 = second_largest_prime_factor(10); 
    long v3 = second_largest_prime_factor(18);
    long v4 = second_largest_prime_factor(334042800); 

    std::ofstream file("PrimosPares.txt");
    file << 6 << " " << v1 <<std::endl;
    file << 10 << " " << v2 <<std::endl;
    file << 18 << " " << v3 <<std::endl;
    file << 334042800 << " " << v4;

    file.close();
}
