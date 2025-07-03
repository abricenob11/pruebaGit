#include "matrix_utils.h"

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void fill_matrixR(std::vector<double> & data, int m, int n){
  // Crear un generador de números aleatorios
    std::random_device rd;  // Dispositivo aleatorio (semilla)
    std::mt19937 gen(rd()); // Motor de generación Mersenne Twister

    // Definir el rango (ejemplo: entre 1 y 100)
    std::uniform_real_distribution<double> distrib(-1.0, 1.0);
    for (int ii = 0; ii < m; ++ii) {
      for (int jj = 0; jj < n; ++jj) {
        data[ii*n + jj] = distrib(gen);
      }
    }
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

//suma de los elementos en la diagonal principal de una matriz
//para matrices cuadradas
double traceMatrix(const std::vector<double> & data, int m){
  double trace = 0.0;
  for(int ii=0; ii<m; ii++){
    trace += data[ii*m + ii];
  }
  return trace;
}

void fillHillbertMatrix(std::vector<double> & data, int m, int n){
  for(int ii = 0; ii < m; ii++){
    for(int jj=0; jj < n; jj++){
      data[ii*n + jj] = 1.0 / (ii+jj+1);
    }
  }
}

void mulTrans(const std::vector<double> & A, int m, int n, std::vector<double> & C){
  std::vector<double> AT (n*m, 0.0);
  transpose_matrix(A, m, n, AT);
  matmul(A, m, n, AT, n, m, C);
}

void llenarIdentidad(std::vector<double> & A, int m){
  for(int ii=0; ii < m; ii++){
    for(int jj=0; jj < m; jj++){
      if(ii==jj) A[ii*m +jj] = 1.0;
    }
  }
}

//matrices cuadradas
void successiveMult(const std::vector<double> & A, int m, std::vector<double> & C, int p){

  if (p < 0) {
    std::cerr << "ERROR: p < 0\n";
    return; 
  } 

  if(p==0){
    C.resize(m*m, 0.0);
    llenarIdentidad(C, m);
    return;
  }

  if(p==1){
    C=A;
    return;
  }

  std::vector<double> copia (m*m, 0.0);
  copia = A;
  for(int ii=1; ii<p; ii++){
    matmul(A, m, m, copia, m, m, C);
    copia=C;
  }
}

//matrices cuadradas
bool idempotent(const std::vector<double> & A, int m, int p, double eps){
  std::vector<double> AP (m*m, 0.0);
  successiveMult(A, m, AP, p);

  for(int ii = 0; ii<m; ii++){
    for(int jj=0; jj<m; jj++){
      if(std::abs(A[ii*m + jj] - AP[ii*m + jj]) > eps) return false;
    }
  }
  return true;
}

bool check_inverse(const std::vector<double> & A, const std::vector<double> & B, int m, double eps){
  std::vector<double> C;
  matmul(A, m, m, B, m, m, C);

  for(int ii=0; ii < m; ii++){
    for(int jj=0; jj < m; jj++){
      int identidad = 0;
      if(ii == jj) identidad = 1;
      if(std::fabs(C[ii*m + jj] - identidad) > eps){
        return false;
      }
    }
  }

  return true;
}

/*bool check_inverse(const std::vector<double> & A,  
                   const std::vector<double> & B, 
                   int m, 
                   double eps) {

  // multiply matrices
  std::vector<double> r;
  matmul(A, m, m, B, m, m, r);

  // matriz resta?
  for (int ii = 0; ii < m; ii++){
    for (int jj = 0; jj < m; jj++) {
      int identidad = 0.0;
      if (ii == jj) identidad = 1.0;
      r[ii*m + jj] = r[ii*m + jj] - identidad;
    }
  }

  // verify elements: early exit
  for (int ii = 0; ii < m; ii++){
    for (int jj = 0; jj < m; jj++) {
      if (std::fabs(r[ii*m + jj]) > eps) {
        return false;
      } 
    }
  }
  return true;
}*/

bool matrixCommute(const std::vector<double> & A, int m, const std::vector<double> & B, double eps){
  std::vector<double> AB;
  std::vector<double> BA;

  matmul(A, m, m, B, m, m, AB);
  matmul(B, m, m, A, m, m, BA);

  for(int ii=0; ii < m; ii++){
    for(int jj=0; jj < m; jj++){
      if(std::fabs(AB[ii*m + jj] - BA[ii*m + jj]) > eps){
        return false;
      }
    }
  }

  return true;
}

bool matrixOrthogonal(const std::vector<double> & A, int mA, int nA, double eps){

  std::vector<double> AT (mA*nA, 0.0);
  std::vector<double> product (mA*mA, 0.0);
  transpose_matrix(A, mA, nA, AT);
  matmul(A, mA, nA, AT, nA, mA, product);

  for(int ii=0; ii < mA; ii++){
    for(int jj=0; jj < mA; jj++){
      int identidad = 0;
      if(ii == jj) identidad = 1;
      if(std::fabs(product[ii*mA + jj] - identidad) > eps){
        return false;
      }
    }
  }

  return true;

}

void sumMatrix(const std::vector<double> & A, int mA, int nA, const std::vector<double> & B, int mB, int nB, std::vector<double> & C){
  if (mA != mB || nA != nB) {
    std::cerr << "ERROR: mA != mB o nA != nB\n";
    return; 
  } 

  C.resize(mA * nA, 0.0);

  for(int ii=0; ii < mA; ii++){
    for(int jj=0; jj < nA; jj++) {
      C[ii*nA + jj] = A[ii*nA + jj] + B[ii*nA + jj];
    }
  }
}

void matrixPolynomial(const std::vector<double> & A, int m, const std::vector<double> & coe, std::vector<double> & result){
  result.resize(m*m, 0.0);
  for(int ii = 0; ii < coe.size(); ii++){
    std::vector<double> copia (m*m, 0.0);
    successiveMult(A, m, copia, ii);

    for(int kk=0; kk<m; kk++){
      for(int jj=0; jj<m; jj++){
        copia[kk*m +jj] *= coe[ii];
      }
    }
    sumMatrix(result, m, m, copia, m, m, result);
  }
}



bool isHermitian(const std::vector<std::complex<double>>& A, int n, double epsilon) {
    for (int ii = 0; ii < n; ii++)
        for (int jj = 0; jj < n; jj++) {
            std::complex<double> diff = A[ii * n + jj] - std::conj(A[jj * n + ii]);
            if (std::abs(diff) > epsilon) return false;
        }
    return true;
}

/*vector<complex<double>> pauliVectorMatrix(const array<double, 3>& v) {
    vector<complex<double>> sigma(4, 0.0); // 2x2 matrix

    complex<double> i(0, 1);
    sigma[0] = v[2];      // (0,0)
    sigma[1] = v[0] - i*v[1]; // (0,1)
    sigma[2] = v[0] + i*v[1]; // (1,0)
    sigma[3] = -v[2];     // (1,1)

    return sigma;
}*/

void pauliVectorMatrix(const std::vector<double>& v, std::vector<std::complex<double>> &sigma) {
    sigma.resize(4, 0.0);

    std::complex<double> i(0, 1);
    sigma[0] = v[2];      // (0,0)
    sigma[1] = v[0] - i*v[1]; // (0,1)
    sigma[2] = v[0] + i*v[1]; // (1,0)
    sigma[3] = -v[2];     // (1,1)
}



