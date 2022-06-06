#include <vector>
#include <iostream>
#include <string>
#include "../string/string_concat.hpp"
#include "../string/to_string.hpp"
int main()
{
    std::vector<std::string> v { "H", "E", "L" };
    std::cout << bg_helper::to_string(v) << std::endl;
    std::cout << bg_helper::concat(true) << std::endl;
}
