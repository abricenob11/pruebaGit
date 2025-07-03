#include <iostream>
#include <valarray>
#include <random>
#include <numeric>  // Para std::accumulate
#include <algorithm> // Para std::copy_if
#include <iterator>  // Para std::back_inserter

using namespace std;


//Para resolver este ejercicio, llenaré un valarray con números aleatorios en el rango [1000, 2500], 
//luego extraeré los valores pares y calcularé su media, todo sin usar bucles explícitos.


int main() {
    const int N = 1000;  // Tamaño del valarray
    const int min_val = 1000;
    const int max_val = 2500;

    // 1. Configurar generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min_val, max_val);

    // 2. Crear y llenar el valarray con números aleatorios
    valarray<int> numbers(N);
    for (auto& num : numbers) {  // Solo para inicialización
        num = distrib(gen);
    }

    // 3. Crear máscara para valores pares
    valarray<bool> even_mask = (numbers % 2) == 0;

    // 4. Extraer valores pares usando la máscara
    valarray<int> even_numbers = numbers[even_mask];

    // 5. Calcular la media de los valores pares
    double mean = 0.0;
    if (even_numbers.size() > 0) {
        mean = static_cast<double>(even_numbers.sum()) / even_numbers.size();
    }

    // 6. Mostrar resultados
    cout << "Total de números generados: " << N << endl;
    cout << "Cantidad de números pares: " << even_numbers.size() << endl;
    cout << "Media de los valores pares: " << mean << endl;

    return 0;
}