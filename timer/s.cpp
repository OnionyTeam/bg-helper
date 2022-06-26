#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

static const double NAN_D = numeric_limits<double>::quiet_NaN();

void die(const char *msg, const char *info) {
	cerr << "** error: " << msg << " \"" << info << '\"';
	exit(1);
}

double str2dou1(const string &str) {
	if (str.empty() || str[0] == '?')
		return NAN_D;
	const char *c_str = str.c_str();
	char *err;
	double x = strtod(c_str, &err);
	if (*err != 0)
		die("unrecognized numeric data", c_str);
	return x;
}

static istringstream string_to_type_stream;

double str2dou2(const string &str) {
	if (str.empty() || str[0] == '?')
		return NAN_D;
	string_to_type_stream.clear();
	string_to_type_stream.str(str);
	double x = 0.0;
	if ((string_to_type_stream >> x).fail())
		die("unrecognized numeric data", str.c_str());
	return x;
}

int main() {
	string str("12345.6789");

	clock_t tStart, tEnd;

	cout << "strtod: ";
	tStart = clock();

	for (int i = 0; i < 1000000; ++i)
		double x = str2dou1(str);

	tEnd = clock();
	cout << tEnd - tStart << endl;

	cout << "sstream: ";
	tStart = clock();

	for (int i = 0; i < 1000000; ++i)
		double x = str2dou2(str);

	tEnd = clock();
	cout << tEnd - tStart << endl;

	return 0;
}
