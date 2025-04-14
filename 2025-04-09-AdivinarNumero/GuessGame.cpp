/*
    Juego de adivinar un numero

    Tener un numero
    Preguntar al usuario el numero
    Informar si lo adivino o no
*/

#include <iostream>
#include <random>

//declaration
void play(int success, int min_val, int max_val);

int main(void){
    play(10, 1, 100);
    return 0;
}

//implementacion

void play(int success, int min_val, int max_val){
    
    const int MIN = min_val;
    const int MAX = max_val;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(MIN, MAX);
    
    const int NUM = distrib(gen);

    std::cout << "\nnumero random: " << NUM <<"\n";

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