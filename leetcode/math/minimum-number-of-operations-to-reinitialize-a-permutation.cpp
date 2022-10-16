// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// array, math, simulation

// 0 1 2 3 4 5  
// 0 3 1 4 2 5
// 0 4 3 2 1 5
// 0 2 4 1 3 5
// 0 1 2 3 4 5


class Solution {
public:
    int reinitializePermutation(int n) {
        int i = 1;
        int c = 0;
        while(true) {
            i = (i & 1) ? n/2 + (i-1)/2 : i/2;
            if(i == 1) break;
            ++c;
        }
        return c+1;
    }
};

// i = 1, 2, 