#include <iostream>

long sumaImpares(int v, long suma);
long secuenciaFibonacci(int n);

int main(int argc, char **argv){
    int n = std::stoi(argv[1]);
    if(n<2){
        std::cout << "Numero fuera de rango \n";
        return 0;
    }
    std::cout<<"La suma de los terminos impares de la secuencia para n: " << n <<" es: " << secuenciaFibonacci(n) << "\n";

    return 0;
}

long sumaImpares(int v, long suma){
    if(v%2!=0){
        suma+=v;
    }
    return suma;
}

long secuenciaFibonacci(int n){
    long suma=1;
    int v1=1;
    int v2=2;
    int contador=2;

    while(v1+v2<=n){  
        if(contador==2){
            v1=v1+v2;
            suma=sumaImpares(v1, suma);       
            contador=1;
        }else{
            v2=v1+v2;
            suma=sumaImpares(v2, suma);
            contador=2;
        }

    }
    return suma;
}

