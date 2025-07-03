# include <iostream>
# include <eigen3/Eigen/Dense>

void mult(int R1, int R2, int d, int n);

int main(int argc, char **argv)
{

    int N = std::stoi(argv[1]); 
   //Eigen::Matrix3d N;
   Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N); //Xd el X para decir que es de tamaño dinámico 
   Eigen::VectorXd b = Eigen::VectorXd::Random(N);

   srand(std::stoi(argv[2]));
   //Eigen::Vector3d b;
   //std::cout.precision(16);
   //std::cout.setf(std::ios::scientific);
   
   
   return 0;
}


void mult(int R1, int R2, int d, int n){
    Eigen::Matrix2d x1;
    Eigen::Matrix2d x2;
    Eigen::Matrix2d x3;

    x1 << 1, (n-1)/R2, 0, 1;
    x2 << 1, 0, d/n, 1;
    x3 << 1, -(n-1)/R1, 0, 1;

    Eigen::Matrix2d A = x1*x2*x3;

    double f = -1/A(0,1);

     

}