// https://leetcode.com/problems/shuffle-an-array/

#include <vector>

using namespace std;

class Solution {
    vector<int> data;
    vector<int> orig;
public:
    Solution(vector<int>& nums) {
        orig = nums;
        data = nums;
    }
    
    vector<int> reset() {
        data = orig;
        return data;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < data.size() - 1; i++)
        {
            int j = i + 1 + (rand() % (data.size() - i - 1));
            swap(data[i], data[j]);
        }
        return data;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */