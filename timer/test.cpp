#include "../string/output.hpp"
#include "timer.hpp"
#include <sstream>
#include <string>
#include <vector>

const int MAX_SIZE = 10;

std::vector<int> str;

void stringstream_test() {
	std::stringstream s;
	Timer t;

	s << "[";
	for (auto e : str) {
		s << e << ", ";
	}
	s << "]";
	std::cout << "stringstream output: " << s.str() << std::endl;
}

void format_test() {

	bg_helper::Format f;
	Timer t;

	f, str;
	bg_helper::println("bg_helper::Format output: ", f.to_string());
}

int main() {
	for (int i = 0; i < MAX_SIZE; ++i) {
		str.push_back(i);
	}
	stringstream_test();
	format_test();
}
