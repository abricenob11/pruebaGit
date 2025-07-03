#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <complex>

double operate(int m);
void llenado(std::vector<double> & A, int m);
void mulTrans(const std::vector<double> & A, int m, int n, std::vector<double> & C);
void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout);
void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C);

double traceMatrix(const std::vector<double> & data, int m);
void print_matrix(const std::vector<double> & data, int m, int n);



int main(void){
    std::cout << operate(5)<< std::endl;
    /*std::cout << f(3)<< std::endl;
    std::cout << f(5)<< std::endl;
    std::cout << f(12)<< std::endl;*/


    return 0;
}

double operate(int m){
    std::vector<double> A(m*m, 0.0);
    std::vector<double> mulT(m*m, 0.0);
    llenado(A, m);
    mulTrans(A, m, m, mulT);

    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    return traceMatrix(mulT, m);

}

void llenado(std::vector<double> & A, int m){
    for(int ii=0; ii<m; ii++){
        for(int jj=0; jj<m; jj++){
            int f = ii+1;
            int c = jj+1;

            int parametro=0;
            if(ii==jj) parametro =1;
            double v1 = (std::pow(f, 2) / (c+1)) * parametro;

            if(ii==jj+1) parametro = 1;
            if(ii!=jj+1) parametro = 0;
            double v2 = (std::sin(2*f-1)) * parametro;

            if(ii+1==jj) parametro = 1;
            if(ii+1!=jj) parametro = 0;
            double v3 = (std::log(std::pow(c, 2) + 2*c)) * parametro;
            //std::cout << v1 << " " << v2 << " " << v3 << std::endl;
            A[ii*m + jj] = v1 + v2 + v3;            
        }
    }
}

    
void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
  // TODO
   for (int ii = 0; ii < m; ++ii) {
     for (int jj = 0; jj < n; ++jj) {
       dataout[jj*m + ii] = datain[ii*n + jj];
     }
   }
}

void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C)
{
  if (nA != mB) {
    std::cerr << "ERROR: nA == mB\n";
    return; 
  }
  // resize result matrix
  int mC = mA;
  int nC = nB;
  C.resize(mC*nC, 0.0);
  // llenar C
  for (int ii = 0; ii < mC; ii++){
    for (int jj = 0; jj < nC; jj++) {
      C[ii*nC + jj] = 0.0;
      for (int kk = 0; kk < nA; kk++) {
        C[ii*nC + jj] += A[ii*nA + kk]*B[kk*nB + jj];
      }
    }   
  }
}


void mulTrans(const std::vector<double> & A, int m, int n, std::vector<double> & C){
  std::vector<double> AT (n*m, 0.0);
  transpose_matrix(A, m, n, AT);
  matmul(A, m, n, AT, n, m, C);
  //print_matrix(C, m, n);
}

double traceMatrix(const std::vector<double> & data, int m){
  double trace = 0.0;
  for(int ii=0; ii<m; ii++){
    trace += data[ii*m + ii];
  }
  return trace;
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}