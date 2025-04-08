#include <iostream>
#include <string>//Importación de la librería que permite usar el tipo de dato String

int main(void) {
    std::string nombre;

    std::cout << "Hola!\n";
    std::cout << "Ingresa tu nombre: ";
    //se podría usar std::cin pero cin no lee espacios, getline lee toda la línea
    std::getline(std::cin, nombre);

    std::cout << "Hello " + nombre + "!\n"; 

    return 0;
}