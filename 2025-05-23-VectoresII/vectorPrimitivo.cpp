#include <iostream>

int main(void){ 
    // Allocate memory for 10 integers
    int * dynamic_array = new int[5];
    // todo: check if memory was actually allocated

    // Use the array
    dynamic_array[0] = 2;
    dynamic_array[1] = 3;
    dynamic_array[2] = 4;
    dynamic_array[3] = 5;
    dynamic_array[4] = 6;

    std::cout << &dynamic_array[0] << std::endl;
    

    // IMPORTANT: Must deallocate manually
    delete[] dynamic_array;

    return 0;
}
