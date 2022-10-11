// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/
// easy, array, hash-table, counting

#include <unordered_map>

using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> target_count;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] == key) {
                target_count[nums[i]]++;
            }
        }
        
        auto itr = target_count.begin();
        auto max_target = itr;
        while(itr != target_count.end()) {
            max_target = (itr->second > max_target->second) ? itr : max_target;
            ++itr;
        }
        
        return max_target->first;
    }
};