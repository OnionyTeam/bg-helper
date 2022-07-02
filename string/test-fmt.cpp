#include <fmt/format.h>
#include <iostream>
#include <vector>

int main() {
	std::tuple<int, int, int> t{1, 2, 3};
	std::cout << fmt::format("{}", t);
}
