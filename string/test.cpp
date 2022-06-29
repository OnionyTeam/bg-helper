#include "to_string.hpp"
#include <bits/stdc++.h>

int main() {
	std::tuple<std::string, std::string> t{"A", "Alen"};
	std::cout << bg_helper::to_string(t) << std::endl;
}
