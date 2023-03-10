# vector-utilities

## Features

`displaying` : vectors can be written in a stream as long as its data type has been overloaded.

`concatenation` : two vectors can be concatenated together.

`multiplication` : vectors can be multiplied by a positive integer *n* to create a vector containing *n* times the values.

`comparing` : two vectors can be compared element by element as long as its data type has been overloaded.

---

## Installation

Download `vector_utilities.h` and add it to your project. Then include it using 

```cpp
#include "vector_utilities.h
```

---

## Examples
\
`displaying`
```cpp
std::vector<int> vec = { 1, 2, 3, 4 };
std::cout << vec << std::endl;
```
output:
```
vector<i>{ 1, 2, 3, 4 }
```

\
`concatenating`
```cpp
std::vector<int> vec1 = { 1, 2, 3, 4 };
std::vector<int> vec2 = { 1, 2 };
std::vector<int> vec3 = vec1 + vec2;
std::cout << vec3 << std::endl;
```
output:
```
vector<i>{ 1, 2, 3, 4, 1, 2 }
```

\
`multiplication`
```cpp
std::vector<int> vec1 = { 1 };
vec1 *= 4;
std::cout << vec1 << std::endl;
```
output:
```
vector<i>{ 1, 1, 1, 1 }
```

\
`comparing`
```cpp
std::vector<int> vec1 = { 1, 2 };
std::vector<int> vec2 = { 1, 2 };
std::vector<int> vec3 = { 1 };
std::cout << (vec1 == vec2) << " " << (vec1 == vec3) << std::endl;
```
output:
```
1 0
```