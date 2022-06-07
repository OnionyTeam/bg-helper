#include "random_generator.hpp"
#include <iostream>

int main()
{
    for (int i = 0; i < 10; ++i) {
        std::cout << bg_helper::generator::random(1, 5) << std::endl;
    }
}
