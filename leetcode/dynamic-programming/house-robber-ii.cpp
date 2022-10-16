// https://leetcode.com/problems/house-robber-ii/
// medium, dynamic-programming, array

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int rob_rec(vector<int>& nums, int start, int end, unordered_map<int, int>& m) {
        if(start > end) return 0;        
        if(m.find(start) != m.end()) return m[start];        
        int res = nums[start] + rob_rec(nums, start + 2, end, m);
        res = max(res, rob_rec(nums, start + 1, end, m));        
        m[start] = res;        
        return res;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        int res = nums[0] + rob_rec(nums, 2, n - 2, m);
        m.clear();
        res = max(res, rob_rec(nums, 1, n - 1, m));
        return res;
    }
};