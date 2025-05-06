#include <iostream>

void digitos(int n);

int main (int argc, char **argv){
    
    digitos(std::stoi(argv[1]));
    
    return 0;
}


void digitos(int n){
    std::cout << n << std::endl;
    int mil=n/1000;
    n-=1000*mil;
    int cent=n/100;
    n-=100*cent;
    int dec=n/10;
    n-=10*dec;
    int un=n;

    std::cout << mil << " " << cent << " " << dec << " " << un << std::endl;
}
