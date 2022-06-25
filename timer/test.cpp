#include "timer.hpp"
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

int main() {
	std::vector<int> a;
	for (int i = 0; i <= 100000; ++i) {
		a.push_back(i);
	}

	std::list<int> b;
	for (int i = 0; i <= 100000; ++i) {
		b.push_back(i);
	}

	auto search_vector = [&]() {
		for (auto &&e : a) {
			if (e == 100000) {
				std::cout << "Found 100000!" << std::endl;
			}
		}
	};
	auto search_list = [&]() {
		for (auto &&e : b) {
			if (e == 100000) {
				std::cout << "Found 100000!" << std::endl;
			}
		}
	};
	get_time(search_vector);
	get_time(search_list);
}
