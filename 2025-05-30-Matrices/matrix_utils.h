#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <complex>

void fill_matrix(std::vector<double> & data, int m, int n);
void fill_matrixR(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);
void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C);
double traceMatrix(const std::vector<double> & data, int m);
void fillHillbertMatrix(std::vector<double> & data, int m, int n);
void mulTrans(const std::vector<double> & A, int m, int n, std::vector<double> & C);
void successiveMult(const std::vector<double> & A, int m, std::vector<double> & C, int p);
bool idempotent(const std::vector<double> & A, int m, int p, double eps);
bool check_inverse(const std::vector<double> & A, const std::vector<double> & B, int m, double eps);
bool matrixCommute(const std::vector<double> & A, int m, const std::vector<double> & B, double eps);
bool matrixOrthogonal(const std::vector<double> & A, int mA, int nA, double eps);
void matrixPolynomial(const std::vector<double> & A, int m, const std::vector<double> & coe, std::vector<double> & result);
void sumMatrix(const std::vector<double> & A, int mA, int nA, const std::vector<double> & B, int mB, int nB, std::vector<double> & C);
void llenarIdentidad(std::vector<double> & A, int m);
bool isHermitian(const std::vector<std::complex<double>>& A, int n, double epsilon);
void pauliVectorMatrix(const std::vector<double>& v, std::vector<std::complex<double>> &sigma);

/* read parameters
          //const int N = std::atoi(argv[1]); // 64
          const int SEED = std::atoi(argv[1]); // 10
          std::vector<int> N{4, 8, 16, 32, 64, 128, 256, 512, 1024};
          std::vector<double> tiempoN(N.size(), 0.0);
          std::cout.precision(16);
          std::cout.setf(std::ios::scientific);

          for(int ii=0; ii<N.size(); ii++){ 

            // data structs
            std::vector<double> A(N[ii]*N[ii], 0.0), B(N[ii]*N[ii], 0.0), C(N[ii]*N[ii], 0.0);
          
            // fill matrices A and B, using random numbers betwwen 0 and 1
            std::mt19937 gen(SEED);
            std::uniform_real_distribution<> dist(0.,1.);
            // lambda function: a local function that captures [] something, receives something (), and return something {}
            // See: https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
            std::generate(A.begin(), A.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function
            std::generate(B.begin(), B.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function
          
            // multiply the matrices A and B and save the result into C. Measure time
            auto start = std::chrono::high_resolution_clock::now();
            matmul(A, N[ii], N[ii], B, N[ii], N[ii], C);
            auto stop = std::chrono::high_resolution_clock::now();
          
            // use the matrix to avoid the compiler removing it
            std::cout << C[N[ii]/2] << std::endl;
          
            // print time
            auto elapsed = std::chrono::duration<double>(stop - start);
            tiempoN[ii] = elapsed.count();
            std::cout << tiempoN[ii] << "\n";
            std::cout << std::endl;
          }

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
          for (int ii=0; ii<tiempoN.size(); ii++){ 
            // Escribir los datos en el archivo
            archivo << N[ii] << " " << tiempoN[ii] / tiempoN[0] << std::endl;
          }
          // Cerrar el archivo
          archivo.close();*/



