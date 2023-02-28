#include <vector>
#include "./vector/vector.hpp"
#include <iterator_traits>
#include <iostream>

int main(void)
{
    std::vector<int> l;
    ft::vector<int> vec1(15, 5);
    ft::vector<int> vec;
    std::vector<int>::iterator it;
    std::iterator_traits<std::vector<int>::iterator>::iterator_category
    vec = vec1;
    vec.resize(20);
    size_t i = vec.size();
    printf("%lu\n", i);
}