// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = x ^ y, c = 0;        
        while(r) {
            c += (r & 1);
            r = r>>1;
        }
        return c;        
    }
};