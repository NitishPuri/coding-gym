// https://leetcode.com/problems/divide-array-into-equal-pairs/
// array, hash-table, bit-manipulation, counting

#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {        
        array<int, 500> s;
        fill(begin(s), end(s), 0);
        for(auto n : nums) {
            if(s[n-1] == 0) s[n-1] = 1;
            else s[n-1] = 0;
        }
        for(auto c: s) {
            if(c != 0) return false;
        }
        return true;        
    }
};