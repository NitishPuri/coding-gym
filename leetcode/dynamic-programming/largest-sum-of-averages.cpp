// https://leetcode.com/problems/largest-sum-of-averages/
// medium, array, dynamic-programming

// 9 1  2  3  9 -> 3
// 9  / 1  2  3  9 -> 2 || 9, 1 / 2 3 9 -> 2

// 9 10 12 15 24
// p = 1 -> 24 / 5 = 4.8
// p = 2 -> i = 0,  (9/1) + (15/4) = 12.75
// p = 2 -> i = 1,  (10/2) + (14/3) = 5 + 4.6 = 9.6
// p = 2 -> i = 2,  (12/3) + (12/2) = 4 + 6 = 10
// p = 2 -> i = 2,  (12/3) + (12/2) = 4 + 6 = 10

#include <vector>

using namespace std;

class Solution {
    // double memo[101][101];
    vector<vector<double>> memo;
    double rec(vector<int>& nums, int start , int k) {        
        if(memo[start][k] != -1.0) return memo[start][k];        
        int n = nums.size();        
        int prefix = (start == 0 ? 0 : nums[start-1]);
        double ans = 0;
        
        if (k == 1) ans = double(nums[n-1] - prefix) / double(n - start);
        else {
            double avg = 0;
            for(int i = start; i < n; ++i) {
                avg = double(nums[i] - prefix)  / double(i - start + 1);
                ans = max(ans, avg + rec(nums, i + 1, k - 1));
            }            
        }        
        memo[start][k] = ans;
        return ans;                
    }
    
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        // memset(&memo, -1.0, sizeof(memo));    
        int n = nums.size();
        memo = vector<vector<double>>(n + 1, vector<double>(k + 1, -1));
        for(int i = 1; i < n; ++i) 
            nums[i]  += nums[i-1];
        return rec(nums, 0, k);                
    }
};