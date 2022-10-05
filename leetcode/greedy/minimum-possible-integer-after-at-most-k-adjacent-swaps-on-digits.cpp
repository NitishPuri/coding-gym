// https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
// 4321 -> 4312 -> 4132 -> 1432 -> 1342

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minInteger(string num, int k) {
        if(k <= 0) return num;        
        
        int n = num.size();
        if(k >= n*(n+1)/2) { 
            sort(num.begin(), num.end());
            return num;
        }
        
        for(int i = 0; i < 10; i++) {
            int idx = num.find(to_string(i));
            if(idx >= 0 && idx <= k) {
                return num[idx] + minInteger(num.substr(0, idx) + num.substr(idx+1), k - idx);
            }
        }
        
        return num;                                        
    }
};