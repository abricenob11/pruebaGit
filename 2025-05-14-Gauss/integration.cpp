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

/*double simpson(double a, double b, int N, fptr fun){
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
    
}*/

double simpson(double a, double b, int N, fptr fun)
{
    // N must be even
	if (N % 2 != 0) {
		N++;
	}
	double Deltax = (b-a)/N;
	double suma1 = 0.0;
    for(int k = 1; k <= N/2; k++) {
		double xk = a + (2*k - 1)*Deltax;
		suma1 += fun(xk);
	}
	double suma2 = 0.0;
    for(int k = 1; k <= N/2 - 1; k++) {
		double xk = a + (2*k)*Deltax;
		suma2 += fun(xk);
	}
	double result = Deltax*(fun(a) + 4*suma1 + 2*suma2 + fun(b))/3.0;

	return result;
}

double richardson(double a, double b, fptr f, int N, algptr alg, int alpha){
    double aux = std::pow(2.0, alpha);
    double v1 = alg(a, b, N, f);
    double v2= alg(a, b, 2*N, f);
    return(aux*v2 - v1)/(aux-1.0);
}

double gauss2(double a, double b, fptr fun){ //en este caso para dos puntos, si fuesen 4, tocaría definir 4 puntos, 4 pesos y sumar los 4 productos

    // aux
    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;

    //define point coordinates 
    double x0 = -1.0/std::sqrt(3.0);
    double x1 = +1.0/std::sqrt(3.0);

    //define weights
    double w0 = 1.0;
    double w1 = 1.0;

    //compute integral
    double result = w0*fun(aux1*x0 + aux2) + w1*fun(aux1*x1 + aux2);
    return aux1*result;
}

/*double gauss3(double a, double b, double c, fptr fun){

    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;

    double x0 = -std::sqrt(3/5);
    double x1 = 0;
    double x2 = +std::sqrt(3/5);

    double w0 = 5.0/9;
    double w1 = 8.0/9;

    double result = w0*fun(aux1*x0 + aux2)
                    + w1*fun(aux1*x1 + aux2)
                    + w0*fun(aux1*x2 + aux2);
    return aux1*result;
}*/

double gauss3(double a, double b, fptr fun)
{
    // aux
    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;

    // define point coordinates
    std::vector<double> x(3);
    x[0] = -std::sqrt(3.0/5.0);
    x[1] = 0;
    x[2] = +std::sqrt(3.0/5.0);
    
    //define weigths
    std::vector<double> w;
    w.resize(3); // para cambiarle el tamano luego de haberlo declarado
    w[0] = 5.0/9.0;
    w[1] = 8.0/9.0;
    w[2] = 5.0/9.0;
    
    // compute integral
    double result = 0.0;
    for(int k = 0; k < 3; ++k){
        result = result + w[k]*fun(aux1*x[k] + aux2);
    }
    return aux1*result;
}

double gauss7(double a, double b, fptr fun)
{
    // aux
    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;

    // define point coordinates
    std::vector<double> x(7);
    x[0] = -0.9491079123427585;
    x[1] = -0.7415311855993945;
    x[2] = -0.4058451513773972;
    x[3] = 0.0;
    x[4] = 0.4058451513773972;
    x[5] = 0.74153118559939450;
    x[6] = 0.9491079123427585;
    
    //define weigths
    std::vector<double> w;
    w.resize(7);
    w[0] = 0.1294849661688697;
    w[1] = 0.2797053914892766;
    w[2] = 0.3818300505051189;
    w[3] = 0.4179591836734694;
    w[4] = 0.3818300505051189;
    w[5] = 0.2797053914892766;
    w[6] = 0.1294849661688697;
    
    // compute integral
    double result = 0.0;
    for(int k = 0; k < 7; ++k){
        result = result + w[k]*fun(aux1*x[k] + aux2);
    }
    return aux1*result;
}