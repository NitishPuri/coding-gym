// https://leetcode.com/problems/number-of-digit-one/

// n0    = 0
// n9    = 1
// n99   = 10 * n9 + 10 = 10(n9 + 1) = n/10 + (n%10!=0) + 
// n999  = 10 * n99 + 10 * 10 = 10(n99 + 10) = 100(n9 + 2 )
// n9999 = 10 * n999 + 10*10*10 = 10(n999 + 100) = 1000(n9 + 3)

// n45678 = n9999 + n(10000 , 45678) = 10000 + 3(n9999) + n(5678) = n(999)

#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int countr = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return countr;        
    }
};