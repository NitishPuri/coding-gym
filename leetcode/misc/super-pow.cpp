// https://leetcode.com/problems/super-pow/

#include <vector>

using namespace std;

// a^b = a * a* a .... b times.
// (x*y) % m = (x%m) * (y%m)

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a == 1) return 1;
        
        a = a % 1337;
        
        int n = b.size();
        bool carry = false;
        bool all_zeroes = true;
        for(int i = 0; i < n; ++i) {
            if(b[i]) all_zeroes = false;
            if(carry) b[i] += 10;
            carry = b[i] & 1;
            b[i] /= 2;
        }
        
        if(all_zeroes) {
            return 1;
        }
        
        int res = carry ? a * superPow(a*a, b) : superPow(a*a, b);
        res = res % 1337;
                        
        return res;
                                
    }
};