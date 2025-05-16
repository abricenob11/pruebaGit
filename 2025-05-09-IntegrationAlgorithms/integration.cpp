#include "integration.h"

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
            //sum1 += fun(2*(a+k*intervalo)-1);
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

double gauss2(double a, double b, fptr fun){
    
}