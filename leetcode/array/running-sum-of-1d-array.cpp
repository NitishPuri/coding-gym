// https://leetcode.com/problems/running-sum-of-1d-array/
// array, easy, prefix-sum

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};