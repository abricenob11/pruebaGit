#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>


//read data and save it
int readData(std::vector<double> &a, std::vector<double> &t);

//compute velocity 
void velocityT(const std::vector<double> &a, const std::vector<double> &t, std::vector<double> &result);

int main(void){
    std::vector<double> a;
    std::vector<double> t;
    std::vector<double> result (3, 0.0);

    readData(a, t);
    velocityT(a, t, result);

    for(auto val : result){
        std::cout << val << " ";
    }

    std::cout << std::endl;

    return 0;
}


int readData(std::vector<double> &a, std::vector<double> &t){

    std::string fname = "accel.txt"; //nombre del archivo a leer
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
        t.push_back(x);
        a.push_back(y);
    }

    //cerrar archivo
    fin.close();

    //mostrar archivos
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << "Mostrar archivos leidos :)" << std::endl; 
    for(int ii = 0; ii < t.size(); ii++){
        std:: cout << t[ii] << " " << a[ii] << std::endl; 
    }

    return 0;
}

void velocityT(const std::vector<double> &a, const std::vector<double> &t, std::vector<double> &result){

    //trapezoid method
    double sum = 0.0;
    for(int ii=1; ii<t.size(); ii++){
        double intervalo = t[ii] - t[ii-1];
        sum += (a[ii] + a[ii-1]) * intervalo / 2.0;
    }
    result[0]=sum;

    //simpson method
    double sum1 = 0.0;
    int N = t.size()-1;
        for(int ii = 1; ii <=N/2-1; ii++){
            if(t[ii]%2==0){ 
                sum1 += 2*a[ii];
            }
        }

        for(int ii = 1; ii <=N/2; ii++){
            if(t[ii]%2!=0){ 
                sum1 += 4*a[ii];
            }
        }

    sum1 += a[0] + a[t.size()-1]; 
    sum1 *= 
    result[1] =sum1;

    /*for(int ii = 1; ii <=; ii++){
        double h = t[ii+1] - t[ii-1];
        sum1 += h/6.0 * (a[ii-1] + 4*a[ii] + a[ii+1]);
    }*/
    /*double sum4 = a[0] + a[t.size()-1];
    for(int ii=0; ii < t.size(); ii++){
        if(t[ii]%2==0){ 
            sum4 += 2*a[ii];
        }else{
            sum4 += 4*a[ii];
        }
    }

    result[3] = */




    //gauss method 2 points
    double sum2 = 0.0;
    for(int ii=1; ii<t.size(); ii++){
        double a1=t[ii-1];
        double b1=t[ii];
        double mid = (a1 + b1) / 2.0;
        double half_len = (b1 - a1) / 2.0;
        
        // Evaluar la función en los puntos de Gauss (transformados al intervalo [a,b])
        double x1 = mid - half_len * (1.0/std::sqrt(3.0));
        double x2 = mid + half_len * (1.0/std::sqrt(3.0));
        
        // Interpolación lineal para estimar los valores en x1 y x2
        double f1 = a[ii-1] + (a[ii] - a[ii-1]) * (x1 - a1) / (b1 - a1);
        double f2 = a[ii-1] + (a[ii] - a[ii-1]) * (x2 - a1) / (b1 - a1);
        
        sum2 += half_len * (f1 + f2); // Pesos son 1 para 2 puntos
    }

    result[2] =sum2;
}