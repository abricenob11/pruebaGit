#include <iostream>
#include <vector>
#include <string>
#include <cmath>

void llenadoRx(std::vector<double> &Rx, const std::vector<double> &angulos);
void llenadoRy(std::vector<double> &Ry, const std::vector<double> &angulos);
void llenadoRz(std::vector<double> &Rz, const std::vector<double> &angulos);
void producto(std::vector<double> &result, const std::vector<double> &matriz);

int main(int argc, char **argv){

  //verifica que se ingrese la cantidad correcta de parametros por consola
  if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " vx, vy, vz, thetax, thetay, thetaz" << std::endl;
        return 1;
  }

  //inicializacion de los vectores que contienen la posicion inicial y los angulos
  std::vector<double> posicion {std::stod(argv[1]), 
                                std::stod(argv[2]),
                                std::stod(argv[3])};
  std::vector<double> angulos {std::stod(argv[4]),
                              std::stod(argv[5]),
                              std::stod(argv[6])};

  //matrices rotacion
  std::vector<double> Rx (9, 0.0);
  std::vector<double> Ry (9, 0.0);
  std::vector<double> Rz (9, 0.0);

  //inicializacion de las matrices rotacion
  llenadoRx(Rx, angulos);
  llenadoRy(Ry, angulos);
  llenadoRz(Rz, angulos);

  //calculando el producto del vector posicion (que va variando) con cada matriz rotacion
  producto(posicion, Rx);
  producto(posicion, Ry);
  producto(posicion, Rz);

  //imprimir posicion final
  for(auto val : posicion){
    std::cout << val << " ";
  }

  std::cout << std::endl;

  return 0;
}

void llenadoRx(std::vector<double> &Rx, const std::vector<double> &angulos){
  Rx[0*3+0] = 1.0; Rx[0*3+1] = 0.0; Rx[0*3+2] = 0.0;
  Rx[1*3+0] = 0.0; Rx[1*3+1] = std::cos(angulos[0]); Rx[1*3+2] = -std::sin(angulos[0]);
  Rx[2*3+0] = 0.0; Rx[2*3+1] = std::sin(angulos[0]); Rx[2*3+2] = std::cos(angulos[0]);
}

void llenadoRy(std::vector<double> &Ry, const std::vector<double> &angulos){
  Ry[0*3+0] = std::cos(angulos[1]); Ry[0*3+1] = 0.0; Ry[0*3+2] = std::sin(angulos[1]);
  Ry[1*3+0] = 0.0; Ry[1*3+1] = 1.0; Ry[1*3+2] = 0.0;
  Ry[2*3+0] = -std::sin(angulos[1]); Ry[2*3+1] = 0.0; Ry[2*3+2] = std::cos(angulos[1]);
}

void llenadoRz(std::vector<double> &Rz, const std::vector<double> &angulos){
  Rz[0*3+0] = std::cos(angulos[2]); Rz[0*3+1] = -std::sin(angulos[2]); Rz[0*3+2] = 0.0;
  Rz[1*3+0] = std::sin(angulos[2]); Rz[1*3+1] = std::cos(angulos[2]); Rz[1*3+2] = 0.0;
  Rz[2*3+0] = 0.0; Rz[2*3+1] = 0.0; Rz[2*3+2] = 1.0;
}

void producto(std::vector<double> &posicion, const std::vector<double> &matriz){
  std::vector<double> vec (posicion);

  for(int ii=0; ii < 3; ii++){
    double suma=0.0;
    for(int jj=0; jj<3; jj++){
      suma += matriz[ii*3+jj] * vec[jj];
    }
    posicion[ii] = suma;
  }
}


