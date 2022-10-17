// https://leetcode.com/problems/jump-game-ii/
// dynamic-programming, medium, array, greedy

#include <array>
using namespace std;

// 2 3 1 1 4
// 3 2 3 2 1  0

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        
        
        array<int, 60> dp;
        fill(begin(dp), end(dp), 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;        
        
        for(int i = 3; i <= n; ++i) {
            for(int j = 2; j <= i/2; ++j) {
                dp[i] = max(dp[i], (i-j) * j);
                dp[i] = max(dp[i], dp[i-j] * j);
            }            
        }
        return dp[n];
        
    }
};