// https://leetcode.com/problems/decompress-run-length-encoded-list/
// easy, array

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;        
        for(int i = 0; i < nums.size(); i += 2) {
            for(int j = 0; j < nums[i]; ++j) {
                res.push_back(nums[i+1]);
            }
        }        
        return res;
    }
};