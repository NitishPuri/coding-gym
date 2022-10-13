// https://leetcode.com/problems/counting-bits/
// easy, dynamic-programming, bit-manipulation

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {        
        vector<int> res(n+1, 0);
        for(int i = 0; i < n + 1; i++) {
            res[i] = (i % 2) + res[i/2];
        }        
        return res;        
    }
};