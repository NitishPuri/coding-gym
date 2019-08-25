#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7};

    std::cout << std::is_sorted(v.begin(), v.end()) << '\n';

    return 0;
}