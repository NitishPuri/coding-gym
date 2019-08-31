#include <iostream>
#include <string>

#include "lib.h"

#define PRINT(a) #a " = " << a << '\n'

int main() {
  std::cout << "Hello World!\n";

  bi_map<int, std::string> map({{1, "one"}, {2, "two"}, {3, "three"}});

  std::cout << PRINT(map.a_to_b(1));
  std::cout << PRINT(map.a_to_b(2));
  std::cout << PRINT(map.a_to_b(3));
  std::cout << PRINT(map.b_to_a("one"));
  std::cout << PRINT(map.b_to_a("two"));
  std::cout << PRINT(map.b_to_a("three"));

  getchar();

  return 0;
}