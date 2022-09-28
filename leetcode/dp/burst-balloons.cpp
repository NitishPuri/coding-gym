// https://leetcode.com/problems/burst-balloons/

#include <vector>

using namespace std;

class Solution {
    
    int max_rec(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {        
        if(start > end) return 0;        
        if(dp[start][end] != -1) return dp[start][end];        
        int ans = 0;        
        for(int i = start; i <= end; i++) {
            int temp = nums[i];
            if(start > 0 ) temp *= nums[start-1];
            if(end < nums.size()-1) temp *= nums[end+1];                        
            ans = max(ans, temp + max_rec(nums, start, i-1, dp) + max_rec(nums, i+1, end, dp));    
        }                
        dp[start][end] = ans;
        return ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp (nums.size(), std::vector<int>(nums.size(), -1));
        return max_rec(nums, 0, nums.size()-1, dp);
    }
};