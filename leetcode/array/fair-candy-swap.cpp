// https://leetcode.com/problems/fair-candy-swap/
// hash-table, binary-search, sorting, easy

#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        auto alice_candies = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        auto bob_candies = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        
        auto diff = (bob_candies - alice_candies)/2;
        
        set<int> bob_set(bobSizes.begin(), bobSizes.end());
        
        for(int i = 0; i < aliceSizes.size(); i++) {
            if(bob_set.find(diff + aliceSizes[i]) != bob_set.end()) {
                return {aliceSizes[i], diff + aliceSizes[i]};
            }
        }
        
        return {};                        
    }
};