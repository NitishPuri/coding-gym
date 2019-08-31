#include <iostream>
#include <sstream>
#include <vector>

template <typename T> std::string to_string_impl(const T &t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}

template <typename... Param>
std::vector<std::string> to_string(const Param &... param) {
  return {to_string_impl(param)...};
}

int main() {
  const auto vec = to_string("hello", 1, 2.2, "tt");
  for (const auto &o : vec) {
    std::cout << o << "\n";
  }
}