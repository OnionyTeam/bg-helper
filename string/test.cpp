#include "../timer/timer.hpp"
#include "to_string.hpp"
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
	using namespace bg_helper;
	Timer t;
	std::tuple m = {1,
					2,
					3,
					4,
					std::make_tuple(3.1415, 9265, "sdad"),
					std::vector<std::string>({"Hello", ",", " world!"})};
	std::cout << to_string(m) << std::endl;
}
