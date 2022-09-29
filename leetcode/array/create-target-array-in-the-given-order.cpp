// https://leetcode.com/problems/create-target-array-in-the-given-order/

#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        list<int> l;
        for(int i = 0; i < nums.size(); i++) {
            l.insert(next(l.begin(), index[i]), nums[i]);
        }        
        return vector<int>(l.begin(), l.end());        
    }
};