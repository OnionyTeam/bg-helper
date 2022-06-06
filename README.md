# bg-helper
一个提供诸多类型的to_string方法集以及其可变参拼接字串方法

## BUILD
...

## How to use?

### to string (bg_helper::to_string)

It provides conversion between **many type**s and strings, including
`(unsinged) int`, `(unsigned) long`, `container: std::vector, std::array, std::list ...`
`double`, `float`

#### Example

```c++
#include "../string/to_string.hpp"
#include <iostream>

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5, 6};
    std::cout << bg_helper::to_string(v) << std::endl; //output: [1,2,3,4,5,6]
    float f = 3.14;
    std::cout << bg_helper::to_string(f) << std::endl; //output: 3.14
    int i = 114514;
    std::cout << bg_helper::to_string(i) << std::endl; //output: 114514
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

int main()
{
    std::cout << bg_helper::concat("PI = ", 3.14) << std::endl; //output: PI = 3.14
    std::vector<int> v {1, 2, 3};
    std::cout << bg_helper::concat("std::vector<int> v =", v) << std::endl; //output: std::vector<int> = [1,2,3]
}
```

## About
...
