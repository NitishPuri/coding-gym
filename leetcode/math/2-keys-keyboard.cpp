// https://leetcode.com/problems/2-keys-keyboard
// math, dynamic-programming

// 1 = 0
// 2 = 2
// 3 = 3
// 4 = 4
// 5 = 5
// 6 = 5
// 7 = 7
// 8 = 6
// 9 = 6
// 10 = 7 = 2 + 5
// 11 = 11
// 12 = 7  = 2 + 2 + 3
// 13 = 13
// 14 = 9
// 15 = 8, 8
// 16 = 8
// 17 = 17
// 18 = 8
// 19 = 19
// 20 = 9

class Solution {
public:
    int minSteps(int n) {
        int res = 0, d = 2;
        while(n > 1) {
            while(n % d == 0) {
                res += d;
                n /= d;
            }
            ++d;
        }        
        return res;
    }
};