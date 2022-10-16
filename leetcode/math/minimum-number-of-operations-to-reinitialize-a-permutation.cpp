// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// array, math, simulation, medium

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
        while(c == 0 || i != 1) {
            i = (i & 1) ? n/2 + (i-1)/2 : i/2;
            ++c;
        }
        return c;
    }
};

// i = 1, 2, 