#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <cmath>
#include <iomanip>

int lecDatos (std::vector<double> & xdata, std::vector<double> & ydata);
int escDatos (double m, double b, double deltam, double deltab, double h);
void calculo (const std::vector<double> & xdata, const std::vector<double> & ydata, std::vector<double> & results);


int main(void){

    std::vector<double> xdata;
    std::vector<double> ydata;
    std::vector<double> results;

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    lecDatos(xdata, ydata);
    calculo(xdata, ydata, results);
    

    double e {1.602176634e-19};
    double h = results[0] * e;

    //Quise escribir un archivo txt para pasar los datos de m, b, deltam, deltab y h
    //(contenidos en el arreglo results) al codigo de python y asi no poner valores fijos en la grafica :D
    escDatos(results[0], results[1], results[2], results[3], h);

    return 0;
}


int lecDatos (std::vector<double> & xdata, std::vector<double> & ydata){
    std::string fname = "datos.txt"; //nombre del archivo a leer
    double x, y;

    //abrir el archivo
    std::ifstream fin(fname);

    //verificar que el archivo abrio correctamente
    if (!fin.is_open()) {
        std::cerr << "Error al abrir el archivo: " << fname << std::endl;
        return 1;
    }

    //leer datos
    while(fin >> x >> y){
        xdata.push_back(x);
        ydata.push_back(y);
    }

    //cerrar archivo
    fin.close();

    //mostrar archivos
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << "Mostrar archivos leidos :)" << std::endl; 
    for(int ii = 0; ii < xdata.size(); ii++){
        std:: cout << xdata[ii] << " " << ydata[ii] << std::endl; 
    }

    return 0;

}

int escDatos (double m, double b, double deltam, double deltab, double h){
// Nombre del archivo de salida
    const std::string nombreArchivo = "resultados.txt";

    // Crear y abrir el archivo
    std::ofstream archivo(nombreArchivo);

    // Verificar si se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al crear el archivo: " << nombreArchivo << std::endl;
        return 1;
    }

    // Configurar formato científico con 5 decimales
    archivo << std::scientific << std::setprecision(5);

    // Escribir los datos en el archivo
    archivo << m << "\t" << b << "\t" << deltam << "\t" << deltab << "\t" << h << std::endl;

    // Cerrar el archivo
    archivo.close();

    return 0;
}

void calculo (const std::vector<double> & xdata, const std::vector<double> & ydata, std::vector<double> & results){

    int N = xdata.size();

    double Ex = std::accumulate(xdata.begin(), xdata.end(), 0.0) / N;
    double Ey = std::accumulate(ydata.begin(), ydata.end(), 0.0) / N;
    double Exx = std::inner_product(xdata.begin(), xdata.end(), xdata.begin(), 0.0) / N;
    double Eyy = std::inner_product(ydata.begin(), ydata.end(), ydata.begin(), 0.0) / N;
    double Exy = std::inner_product(xdata.begin(), xdata.end(), ydata.begin(), 0.0) /N;
    
    double m = (Exy - Ex*Ey) / (Exx - std::pow(Ex, 2));
    double b = (Exx*Ey - Ex*Exy) / (Exx - std::pow(Ex, 2));
    double s2 = (N / (N-2)) * (Eyy - std::pow(Ey, 2) - (std::pow(m, 2)*(Exx - std::pow(Ex, 2))));

    double deltam = std::sqrt(s2 / (N * (Exx - std::pow(Ex, 2))));
    double deltab = std::sqrt(std::pow(deltam, 2)*Exx);

    results.push_back(m);
    results.push_back(b);
    results.push_back(deltam);
    results.push_back(deltab);
}

