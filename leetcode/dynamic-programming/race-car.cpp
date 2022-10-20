// https://leetcode.com/problems/race-car/
// dynamic-programming, hard, incomplete

// 1 2 4 8 16 32
// 0 1 3 7 15 31 63
// n*A -> s = 2^n , p = 2^n - 1

// 17 -> 10001

// 4A -> s = 16, p = 15 => 4ARRA -> s = 2, p = 16 4ARRAA -> s = 4, p = 18 -> RA -> s = -1, p = 17
// 5A -> s = 32, p = 31

#include <numeric>
using namespace std;

class Solution {
    // unordered_map<int, int> m;
    int rec(int target) {
        if(target == 0) return 0;
        int a = int(log2(target));
        int a2 = 1 << a;

        if(target == a2 - 1) return a;
        if(target == a2*2 - 1) return a + 1;

        return min(a + 1 + 1 + rec(target - a2 + 1),  a + 1 + 1 + rec(2*a2 - 1 - target));
    }
public:
    int racecar(int target) {
        // m.clear();
        return rec(target);        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.racecar(5);
    return 0;
}
