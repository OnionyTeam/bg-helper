#include "output.hpp"
#include "to_string.hpp"
#include <iostream>
#include <map>

using namespace bg_helper;

class A {};
int main() {
	A a;
	/* std::vector<A> m{a}; */
	println<wchar_t>(a);
}
