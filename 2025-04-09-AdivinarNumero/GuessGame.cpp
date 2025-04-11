/*
    Juego de adivinar un numero

    Tener un numero
    Preguntar al usuario el numero
    Informar si lo adivino o no
*/

#include <iostream>

//declaration
void play(void);

int main(void){
    play();
    return 0;
}

//implementacion

void play(void){
    const int NUM = 10;

    const int MIN = 1;
    const int MAX = 100;


    int guessed_number = NUM+1;

    while(guessed_number != NUM){ 
        
        std::cout<< "Adivina un numero entre " << MIN << " y " << MAX << "\n";
        std::cin>> guessed_number;

            //validación del rango

            if(guessed_number<=100 && guessed_number>=1){ 

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
}