#include "output.hpp"
#include "to_string.hpp"
#include <iostream>
#include <vector>

int a[10][10][10];

int main() {
    using namespace bg_helper;
    auto s = to_string(a);
    std::cout << s << std::endl;
}
