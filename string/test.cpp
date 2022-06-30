#include "../timer/timer.hpp"
#include "output.hpp"
#include "to_string.hpp"
#include <iostream>
#include <map>
#include <unordered_map>

int main() {
	using namespace bg_helper;
	Format f;
	std::vector v{"Hello", ", world!"};
	std::map<int, std::string> m{
		{1, "China"}, {2, "America"}, {3, "Japan"}, {4, "UK"}};
	std::pair p = {"123", "456"};
	std::tuple<int, int, int> tup = {1234, 5678, 9876};
	std::tuple<std::vector<std::string>, std::tuple<int, int>> tup2{
		{"ABC", "DEF"}, std::make_tuple(1, 2)};
	println("Starting bg_helper test...");
	Timer t;
	f | "===basic type===\n";
	f | "int: " | 114514 | "\tdouble: " | 3.141592653589 | "\n";
	f | "===containers===\n";
	f | "std::vector<std::string> v: " | v | "\n";
	f | "std::map<int, std::string>: " | m | "\n";
	f | "std::pair<std::string, std::string>: " | "\n";
	f | "std::tuple<int, int, int>: " | tup | "\n";
	f | "===composite type===\n";
	f | "std::tuple<std::vector<std::string>, std::tuple<int,int>>: " | tup2;
	println(f);
}
