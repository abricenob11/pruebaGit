# include <iostream>
# include <eigen3/Eigen/Dense>

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
   
   //A << 1,2,3,  4,5,6,  7,8,10;
   //b << 3, 3, 4;
   std::cout << "Here is the matrix A:\n" << A << std::endl;
   std::cout << "Here is the vector b:\n" << b << std::endl;
   Eigen::Vector3d x = A.colPivHouseholderQr().solve(b);
   std::cout << "The solution is:\n" << x << std::endl;
   std::cout << (A*x - b).norm() << "\n";
   return 0;
}