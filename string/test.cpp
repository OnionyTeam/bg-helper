#include "../timer/timer.hpp"
#include "to_string.hpp"
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
	Timer t;
	std::vector<std::vector<std::string>> m;
	for (int i = 0; i < 1000; ++i)
		m.push_back({"A", "B"});
	std::cout << bg_helper::to_string(m) << std::endl;
}
