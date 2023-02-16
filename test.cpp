#include <vector>
#include "./vector/vector.hpp"
#include <iostream>

int main(void)
{
    ft::vector<int> vec1(130, 100);
    ft::vector<int> vec;
    vec = vec1;
    size_t i = vec.max_size();
    printf("%lu\n", i);
    std::vector<int> v;
    std::cout << v.max_size() << std::endl;
}