#include <vector>
#include "./vector/vector.hpp"
#include <iostream>

int main(void)
{
    ft::vector<int> vec1(15, 5);
    ft::vector<int> vec;
    vec = vec1;
    vec.resize(20);
    size_t i = vec.size();
    printf("%lu\n", i);
}