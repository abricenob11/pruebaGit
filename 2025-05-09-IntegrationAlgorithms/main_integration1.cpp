#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>

using fptr = std::function<double(double)>;

double trapezoid(double a, double b, int n, fptr fun);
double simpson(double a, double b, int N, fptr fun);

using algptr = std::function<double(double, double, int, fptr)>;

double richardson(double a, double b, fptr f, int N,  algptr alg, int alpha);

double fun(double x);

int main(int argc, char **argv){

    double exact_result {1.56898093601156};

    double a = -5.0;
    double b = 5.0;

    std::ofstream file("errores.txt");

    file.precision(15);
    file.setf(std::ios::scientific);

    for(int N=2; N<=2000000; N*=2){
        double trapecio = trapezoid(a, b, N, fun);
        double simp = simpson(a, b, N, fun);
        double richardson_tra = richardson(a, b, fun, N, trapezoid, 2);
        double richardson_simp = richardson(a, b, fun, N, simpson, 4);
        double error_tra = std::abs(1.0 - trapecio/exact_result);
        double error_simp = std::abs(1.0 - simp/exact_result);
        double error_richardson_tra = std::abs(1.0 - richardson_tra/exact_result);
        double error_richardson_simp = std::abs(1.0 - richardson_simp/exact_result);
        file << N << " "
                << error_tra << " "
                << error_simp << " "
                << error_richardson_tra << " "
                << error_richardson_simp << " "
                << std::endl;
    }

    file.close();

    return 0;
}

double fun(double x){
    return std::sin(std::pow(std::exp(1.0), x));
}

double trapezoid(double a, double b, int N, fptr fun){

    double intervalo = (b-a)/N;
    double v1 = fun(a);
    double v2 = fun(b);
    double sum=0.0;

    for(int k= 1; k<=N-1; k++){
        double xk = a+(k*intervalo);
        sum += fun(xk);
    }

    return intervalo*((v1/2) + sum + (v2/2));
}

double simpson(double a, double b, int N, fptr fun){
    // N tiene que ser par
    if(N%2==0){ 
        double intervalo = (b-a)/N;
        double v1 = fun(a);
        double v2 = fun(b);
        double sum1 = 0.0;
        double sum2 = 0.0; 
        for(int k=1; k<=N/2; k++){
            sum1 += fun(a+(2*k-1)*intervalo);
        }

        for(int k=1; k<=N/2-1; k++){
            sum2 += fun(a+(2*k)*intervalo);
        }

        return (intervalo/3)*(v1 + 4*sum1 + 2*sum2 + v2);
    } else return 0;
    
}

double richardson(double a, double b, fptr f, int N, algptr alg, int alpha){
    double aux = std::pow(2.0, alpha);
    double v1 = alg(a, b, N, f);
    double v2= alg(a, b, 2*N, f);
    return(aux*v2 - v1)/(aux-1.0);
}

