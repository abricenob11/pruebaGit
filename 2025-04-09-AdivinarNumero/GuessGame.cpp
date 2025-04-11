/*
    Juego de adivinar un numero

    Tener un numero
    Preguntar al usuario el numero
    Informar si lo adivino o no
*/

#include <iostream>

int main(void){
    const int NUM = 10;
    int guessed_number = NUM+1;

    while(guessed_number != NUM){ 
        
        std::cout<< "Adivina un numero entre 1 y 100:\n";
        std::cin>> guessed_number;

            //validación del rango

            if(guessed_number<100 && guessed_number>1){ 

                if(guessed_number == NUM){
                    std::cout << "Ganó!!! ;)\n";
                } else if(guessed_number > NUM){
                    std::cout << "Te pasaste\n";
                } else{ // es menor
                    std::cout << "Te falta\n";
                }
            }else{
                std::cout << "Numero en el rango incorrecto\n";
            }

    }
    return 0;
}