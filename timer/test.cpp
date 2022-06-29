#include "../string/output.hpp"
#include "timer.hpp"
#include <charconv>
#include <fmt/format.h>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace bg_helper;

int main() {
	std::tuple<std::tuple<int, int>, int> t({1, 2}, 3);
	std::cout << to_string(t) << std::endl;
}
