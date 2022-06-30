# bg-helper
A *POWERFUL* toolset!!!

*Uses many features that are only available in C++20*

## example

```c++
#include "../timer/timer.hpp"
#include "output.hpp"
#include "to_string.hpp"
#include <map>

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
```
![example](https://raw.githubusercontent.com/OnionyTeam/bg-helper/main/images/screenshot.jpg)

## How to use?

### Format

```c++
#include "string/output.hpp"
#include <iostream>

int main()
{
    bg_helper::Format f;
    f | "PI = " | 3.1415926535897;
    std::cout << f << std::endl; //output: PI = 3.1415926535897
}
```

### Timer

```c++
#include "timer/timer.hpp"

int main()
{
    Timer t;
    // Do anything
}

// output: It took xxx millisecond to call xxx function in xxxx
```

### to string (bg_helper::to_string)

It provides conversion between **many type**s and strings, including
`(unsinged) int`, `(unsigned) long`, `container`,
`double`, `float`, `bool`

#### Example

```c++
#include "../string/to_string.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5, 6};
    std::cout << bg_helper::to_string(v) << std::endl; //output: [1,2,3,4,5,6]
    float f = 3.14;
    std::cout << bg_helper::to_string(f) << std::endl; //output: 3.14
    int i = 114514;
    std::cout << bg_helper::to_string(i) << std::endl; //output: 114514
    bool b = true;
    std::cout << bg_helper::to_string(b) << std::endl; //output: True
}
```

### concatenate strings (bg_helper::connect)
#### Example

```c++
#include "../string/string_concat.hpp"
#include <iostream>

int main()
{
    std::cout << bg_helper::connect("Hello ", "World!") << std::endl; //output: Hello World!
}
```

### concatenate different types to string (bg_helper::concat)
Actually, it is a combination of bg_helper::connect() and bg_helper::to_string()

### Example

```c++
#include "../string/string_concat.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << bg_helper::concat("PI = ", 3.14) << std::endl; //output: PI = 3.14
    std::vector<int> v {1, 2, 3};
    std::cout << bg_helper::concat("std::vector<int> v =", v) << std::endl; //output: std::vector<int> = [1,2,3]
}
```

## About
...
