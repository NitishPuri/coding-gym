// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, long n) {
        if(x == 1.0) return 1;
        if(x == 0.0) return 0;
        // if(n == INT_MIN) return (1/x) * myPow(1/x, n+1);
        if(n < 0) return myPow(1/x, -n);                
        if(n == 0) return 1;
        if( n == 1 ) return x;
        return (n % 2 == 1) ? x * myPow(x*x, n/2) : myPow(x*x, n/2);        
    }
};