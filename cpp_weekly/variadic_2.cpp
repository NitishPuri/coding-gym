#include <sstream>
#include <iostream>
#include <vector>

template<typename ... Param>
std::vector<std::string> to_string(const Param& ... param) {
    std::stringstream ss;
    return { (
                ss.str(""),
                ss << param, 
                ss.str()
            )... 
        };
}

int main() {
    const auto vec = to_string("hello", 1, 2.2, "tt");
    for(const auto& o : vec) {
        std::cout << o << "\n";
    }
}