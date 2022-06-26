#include "../string/output.hpp"
#include "timer.hpp"
#include <charconv>
#include <sstream>
#include <string>
#include <vector>

using namespace bg_helper;
/* using namespace std; */

int main() {
	Timer t;
	Format f;
	float fl = 3.141592653F;
	double dl = 3.14159265358979324626;
	f | "Float: " | fl | "\t" | "Double: " | dl;
	std::cout << f << std::endl;
}
