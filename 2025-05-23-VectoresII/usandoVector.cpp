#include <iostream>
#include <vector>
#include <algorithm>

int main(void){ 

    /*
    std::vector<int> v2 (begin(v1)+3, end(v1)))
    std::vector<int> v2 (5, 3) -  3,3,3,3,3
    .front(primer elemento) y .back (ultimo)
    .size (lo realmente usado) y .capacity
    */
    std::vector<int> data {2,3,4,5,6};
    std::cout << &data.front() << std::endl;
    data.push_back(10);

    auto print = [](int a){std::cout<< a << std::endl;};
    std::for_each(data.begin(), data.end(), print);

    return 0;
}
