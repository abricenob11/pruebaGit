#include <iostream>
#include <valarray>
#include <cmath>
#include <numeric>
#include <iomanip>

void print(std::string msg, const std::valarray<double>& v)
{
    std::cout << msg << " ";
    for (auto n: v) { std::cout << " " << n; }
    std::cout << '\n';
}


int main(void){
    const int N=10;
    std::valarray<double> x (N);

    //init with N points in between [0, 2pi)
    //fill with 0,1,2,3...N-1
    //multiply by (xmax-xmin)/N

    //std::iota(x.begin(), x.end(), 0.0);
    //print("iota applied: ", x);

    std::iota(std::begin(x), std::end(x), 0.0);
    print("iota applied: ", x);

    x = x*(2*M_PI/N);
    print("multiplied: ", x);

    std::valarray<double> y = std::sin(x);
    print("sin : ", y);

    std::valarray<double> filtered = y[std::abs(y) <= 0.5];
    print("filter : ", filtered);

}





/*int main()
{
    std::valarray<int> v1 (1000);
    std::iota(v1.begin(), v1.end(), 0.0);

    return 0;
}*/

