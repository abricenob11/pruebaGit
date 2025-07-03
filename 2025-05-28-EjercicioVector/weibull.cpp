#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cmath>
#include <cstdlib>

using namespace std;

/*Histogram from random numbers, saving to file. Write a program that generates N random numbers, 
with the Weibull distribution and a given seed. Both N, the seed, and the Weibull parameters must 
read from the command line. Also, you must compute the histogram and print it to a file.*/

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Uso: " << argv[0] << " N seed a b\n";
        return 1;
    }

    int N = atoi(argv[1]);
    unsigned int seed = atoi(argv[2]);
    double a = atof(argv[3]); // shape
    double b = atof(argv[4]); // scale

    default_random_engine engine(seed);
    weibull_distribution<double> dist(a, b);

    vector<double> values(N);
    for (int i = 0; i < N; ++i)
        values[i] = dist(engine);

    // Crear histograma
    int num_bins = 20;
    double max_val = *max_element(values.begin(), values.end());
    double bin_width = max_val / num_bins;

    vector<int> histogram(num_bins, 0);
    for (double v : values) {
        int bin = min(static_cast<int>(v / bin_width), num_bins - 1);
        histogram[bin]++;
    }

    ofstream outfile("histograma.txt");
    if (!outfile) {
        cerr << "No se pudo escribir el archivo.\n";
        return 1;
    }

    for (int i = 0; i < num_bins; ++i)
        outfile << "[" << i * bin_width << ", " << (i + 1) * bin_width << "): " << histogram[i] << "\n";

    return 0;
}


//./histograma 10000 42 2.0 1.5
//10000 numero de datos
//42 semilla 
//2.0 parametro a shape
// 1.5 parametro b scale
