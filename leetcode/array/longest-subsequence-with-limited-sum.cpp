// https://leetcode.com/problems/longest-subsequence-with-limited-sum/
// array, easy, binary-search, greedy, sorting, prefix-sum


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums), end(nums));
        
        for(int i = 1; i < nums.size(); ++i)
            nums[i] = nums[i] + nums[i-1];
        
        int m = queries.size();
        vector<int> ans(m, 0);
        for(int i = 0; i < m; ++i) {
            ans[i] = distance(begin(nums), upper_bound(begin(nums), end(nums), queries[i]));
        }
        
        return ans;
    }
};