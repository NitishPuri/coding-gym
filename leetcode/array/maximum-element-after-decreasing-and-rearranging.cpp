// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
// medium, greedy, sorting, array

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());        
        int pre = 0;
        for(auto a : arr) {
            pre = min(pre + 1, a);
        }        
        return pre;        
    }
};