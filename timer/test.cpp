#include "../string/output.hpp"
#include "timer.hpp"
#include <charconv>
#include <sstream>
#include <string>
#include <vector>

using namespace bg_helper;
/* using namespace std; */

void using_format() {
	Timer t;
	Format f;
	float fl = 3.141592653F;
	double dl = 3.14159265358979324626;
	f | "Float: " | fl | "\t" | "Double: " | dl;
	std::cout << f << std::endl;
}

void using_stringstream() {
	Timer t;
	float fl = 3.141592653F;
	double dl = 3.14159265358979324626;
	std::stringstream ss;
	ss << "Float: " << fl << "\t"
	   << "Double: " << dl;
	std::cout << ss.str() << std::endl;
}

int main() {
	using_stringstream();
	using_format();
}
