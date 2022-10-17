// https://leetcode.com/problems/jump-game-ii/
// dynamic-programming, medium, array, greedy

#include <vector>
using namespace std;

// 2 3 1 1 4
// 3 2 3 2 1  0

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);        
        for(int i = n-2; i >= 0; --i) {
            int res = n;
            for(int j = 1; j <= min( nums[i] , n - i - 1) ; ++j) {
                res = min(res, dp[i+j] + 1);
            }
            dp[i] = res;            
        }        
        return dp[0];
        
    }
};