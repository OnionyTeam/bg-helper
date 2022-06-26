# bg-helper
A *POWERFUL* toolset!!!

*Uses many features that are only available in C++20*


## BUILD
...

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

// output: It took xxx millisecond to call int main() function in xxxx
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
