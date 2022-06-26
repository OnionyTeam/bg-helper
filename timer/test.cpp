#include "../string/output.hpp"
#include "timer.hpp"
#include <sstream>
#include <string>
#include <vector>

const int MAX_SIZE = 10;

void stringstream_test() {
	std::stringstream s;

	Timer t;
	for (int i = 0; i < MAX_SIZE; ++i) {
		s << "ABCDEFGHIJSJDLDJLSJDSDJSDLKDJKLSDJ";
	}
	std::cout << "stringstream output: " << s.str() << std::endl;
}

void format_test() {

	bg_helper::Format f;
	Timer t;

	for (int i = 0; i < MAX_SIZE; ++i) {
		/* ss.append("A"); */
		f, "ABCDEFGHIJSJDLDJLSJDSDJSDLKDJKLSDJ";
	}
	std::cout << "bg_helper::Format output: " << f << std::endl;
}

int main() {
	stringstream_test();
	format_test();
}
