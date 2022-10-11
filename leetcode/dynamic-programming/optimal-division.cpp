// https://leetcode.com/problems/optimal-division/

// 2 3 4
// 

#include <vector>
#include <string>

using namespace std;

class Solution {
    struct T {
        float min_val = 0;
        float max_val = 0;
        string min_str;
        string max_str;
    };
    vector<vector<T>> memo;
    T opDiv_rec(vector<int>& nums, int start, int end) {
        if(memo[start][end].min_val != 0 && memo[start][end].max_val != 0) {
            return memo[start][end];
        }
        T t;
        if(start == end) {
            t.min_val = nums[start];
            t.max_val = nums[start];
            t.min_str = to_string(nums[start]);
            t.max_str = to_string(nums[start]);
            memo[start][end] = t;
            return t;
        }        
        t.min_val = FLT_MAX;
        t.max_val = FLT_MIN;
        t.min_str = "";
        t.max_str = "";
        for(int i = start; i < end; i++) {
            auto left = opDiv_rec(nums, start, i);
            auto right = opDiv_rec(nums, i+1, end);
            if(t.min_val > left.min_val / right.max_val) {
                t.min_val = left.min_val / right.max_val;
                t.min_str = left.min_str + "/" + (i + 1 != end ? "(" : "") 
                    + right.max_str + (i+1 != end ? ")" : "");
            }
            if(t.max_val < left.max_val / right.min_val) {
                t.max_val = left.max_val / right.min_val;
                t.max_str = left.max_str + "/" + (i + 1 != end ? "(" : "") 
                    + right.min_str + (i+1 != end ? ")" : "");
            }
        }
        memo[start][end] = t;
        return t;        
    }
    
public:
    string optimalDivision(vector<int>& nums) {
        memo.resize(nums.size(), vector<T>(nums.size(), T{}));
        auto res = opDiv_rec(nums, 0, nums.size() - 1);
        return res.max_str;
    }
};