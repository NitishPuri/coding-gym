// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <vector>

using namespace std;


// arr = 1, 1, 0, 1
// i   = 0, 1, 2, 3


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr_seq_len = 0;
        int prev_seq_len = 0;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                curr_seq_len++;
            }else{
                prev_seq_len = curr_seq_len;
                curr_seq_len = 0;
            }
            ans = max(ans, prev_seq_len + curr_seq_len);
        }
        
        if(ans == nums.size())
            return ans - 1;
        else
            return ans;           
    }            
};
