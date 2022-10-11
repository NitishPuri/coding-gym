// https://leetcode.com/problems/build-array-from-permutation/
// easy, aray, simulation

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {        
        auto ans = nums;
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = nums[nums[i]];
        }
        
        return ans;        
    }
};