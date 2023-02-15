#include <vector>
#include "./vector/vector.hpp"
#include <iostream>

int main(void)
{
    std::vector<std::string> vec;
    std::cout << vec.max_size() << std::endl;
    ft::vector<int> vec1(10, 10);
    printf("%d\n", vec1[1]);


}