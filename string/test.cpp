#include "output.hpp"
#include <iostream>

int main() {
	bg_helper::Format f;
	f, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3;
	std::cout << f << std::endl;
}
