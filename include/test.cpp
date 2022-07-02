#include "../timer/timer.hpp"
#include "output.hpp"
#include "to_string.hpp"
#include <map>

class A {};

int main() {
	using namespace bg_helper;
	Format f(2);
	A a;
	print(to_string(a));
}
