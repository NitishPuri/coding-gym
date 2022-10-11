// https://leetcode.com/problems/sum-of-two-integers/
// medium, math, bit-manipulation

// 2 + 3 = 5
// 2 = 010
// 3 = 011  001 + 010<<1


// 5 = 101

// res = 0000
// carry = 0
// a = 010 = 011
// res = 0 | (  0 ^ 1 ^ 0 ) << 0 = 1
// carry = 0, a = 01, b = 01
// res = 1 | ( 1 ^ 1 ^ 0  ) << 1 = 01
// carry = 1, a = 0, b = 0





class Solution {
public:
    int getSum(int a, int b) {                
        unsigned int c;
        while(b != 0) {
            c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};