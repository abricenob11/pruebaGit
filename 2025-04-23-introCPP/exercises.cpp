#include <iostream>

bool isPrime(int n);

int main(void){

bool ans = isPrime(10000000000);
if(ans){
    std::cout<<"El numero es primo\n";
}else{
    std::cout<<"El numero no es primo\n";
}

}

bool isPrime(int n){
    int contador = 0;
        if(n<=0){
            std::cout<<"number out of range\n";
            return false;
        }else if(n>0){
            for(int i=1; i<=n; i++){
                if(n%i==0){
                    contador++;
                }
            }
        } 
    if(contador==2){
        return true;
    } else{
        return false;
    }

}

