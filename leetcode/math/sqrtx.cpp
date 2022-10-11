// https://leetcode.com/problems/sqrtx/
// easy, math, binary-search

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        long left = 1, right = x;        
        while(left < right) {
            long curr = (left + right) / 2L;
            long sqr = curr * curr;
            if(sqr > x) {
                right = curr;
            } else if(sqr < x) {
                left = curr;
            } else {
                return curr;
            }
            
            if(right - left == 1) {
                break;
            }            
        }
        return left;
    }
};