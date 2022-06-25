#include "../string/output.hpp"
#include "../string/string_concat.hpp"
#include "../string/to_string.hpp"
#include <iostream>
#include <locale>
#include <vector>

using namespace bg_helper;
int main() {
	std::setlocale(LC_ALL, "");
	std::vector<std::string> s{"MDSHIT", "FUCKINGYOUT!", "READLY"};
	std::cout << bg_helper::concat("std::vector<std::string> s = ", s)
			  << std::endl; // output: PI
}
