#include "../string/output.hpp"
#include "timer.hpp"
#include <charconv>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace bg_helper;

class A {
  public:
	std::string to_string() const { return "Hello"; }
};

int main() {
	Timer t;
	std::vector<std::vector<std::vector<int>>> v{
		{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}},
		{{4, 4, 4}, {5, 5, 5}, {6, 6, 6}},
		{{7, 7, 7}, {8, 8, 8}, {9, 9, 9}}};
	Format f;
	A a;
	f | "std::vector<std::vector<int>> v: " | v | "\n";
	f | f | f | f;
	std::cout << f << std::endl;
}
