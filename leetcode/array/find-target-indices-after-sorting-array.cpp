// https://leetcode.com/problems/find-target-indices-after-sorting-array/
// easy, binary-search, sorting, array

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int count_target = 0;
        int count_less = 0;
        for(int n : nums) {
            if(n == target) count_target++;
            if(n < target) count_less++;
        }
        
        vector<int> res(count_target, 0);
        iota(res.begin(), res.end(), count_less);
        return res;        
    }
};