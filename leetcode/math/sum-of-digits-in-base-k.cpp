// https://leetcode.com/problems/sum-of-digits-in-base-k/
// easy, math

class Solution {
public:
    int sumBase(int n, int k) {        
        int res = 0;
        while(n) {
            res += (n % k);
            n = n / k;
        }        
        return res;        
    }
};