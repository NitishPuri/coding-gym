// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// array

#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {        
        int max_c = candies[0];
        for(auto c : candies) max_c = max(max_c, c);
        
        int n = candies.size();
        vector<bool> res(n, false);
        for(int i = 0; i < n; ++i) {
            res[i] = (candies[i] + extraCandies >= max_c);
        }
        
        return res;
    }
};