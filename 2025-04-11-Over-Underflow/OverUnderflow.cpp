#include <iostream>
int main(void) {
  // con enteros
  int b {-3000000000}; //es una buena forma de inicializar variables. Permite ver errores como con numero grandes para ciertos tipos de variables. A diferencia de b=-3000000000
  //int b = -3000000000;
  std::cout << "b = " << b << "\n";
  std::cout << "3*b = " << 3*b << "\n";
  int a = -2000000000;
  std::cout << "a = " << a << "\n";
  // con flotantes
  double x = 3000000000;
  std::cout << "x = " << x << "\n";
  x = 3.24e307;
  std::cout << "x = " << x << "\n";
  std::cout << "100000*x = " << 1.0e5*x << "\n";
  x = 3.24e310;
  std::cout << "x = " << x << "\n";
  x = 3.24e-310;
  std::cout << "x = " << x << "\n";
  x = 3.24e-326;
  std::cout << "x = " << x << "\n";
  return 0;
}