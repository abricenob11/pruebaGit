#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//Use a vector to compute the counter histogram for some data read from a file.



int main() {
    ifstream infile("datos.txt");
    if (!infile) {
        cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }

    vector<int> data;
    int value;

    while (infile >> value)
        data.push_back(value);

    int max_val = *max_element(data.begin(), data.end());
    vector<int> histogram(max_val + 1, 0);

    for (int v : data)
        histogram[v]++;

    for (int i = 0; i < histogram.size(); ++i)
        cout << i << ": " << histogram[i] << "\n";

    return 0;
}
