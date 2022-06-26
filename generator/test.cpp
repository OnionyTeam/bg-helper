#include "../string/output.hpp"
#include "../timer/timer.hpp"
#include "random_generator.hpp"
#include <algorithm>
#include <iostream>

int main() {
	using namespace bg_helper::generator;
	std::vector<int> v;
	auto f = [&]() -> int {
		return bg_helper::generator::random.randdigit(0, 0xFFFF);
	};
	Timer t;
	for (int i = 0; i < 100; ++i) {
		v.push_back(f());
	}
	bg_helper::Format fmt(v);
	std::cout << fmt << std::endl;
}
