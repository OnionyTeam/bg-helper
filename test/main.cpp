#include "../string/string_concat.hpp"
#include "../string/to_string.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << bg_helper::concat("PI = ", 3.14) << std::endl; //output: PI = 3.14
    std::vector<int> v {1, 2, 3};
    std::cout << bg_helper::concat("std::vector<int> v =", v) << std::endl; //output: std::vector<int> = [1,2,3]
}
