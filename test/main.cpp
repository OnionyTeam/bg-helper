#include <vector>
#include <iostream>
#include <string>
#include "../string/string_concat.hpp"
#include "../string/to_string.hpp"
int main()
{
    std::vector<std::string> v2 { "HELLO", "WORLD!" };
    std::cout << bg_helper::concat(v2) << std::endl;
}
