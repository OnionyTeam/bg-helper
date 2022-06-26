#include "dtoa_milo.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	char buff[50];
	double pi = 3.141592653589793;
	dtoa_milo(pi, buff);
	cout << string(buff) << endl;
}
