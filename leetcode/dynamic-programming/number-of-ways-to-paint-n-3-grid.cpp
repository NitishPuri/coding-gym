// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid
// dynamic-programming, hard

// n = 1 -> 12
// n = 2 -> (  [when first and last are same colors]6 * (  )  )



// aba -> 6, abc -> 6 (6, 6)
// aba -> bcb, bab, bac, cac, cab, -> 5  (2, 3)
// abc -> bab, bca, bcb, cab, -> 3  (2, 2)



class Solution {
public:
    int numOfWays(int n) {
        const int M = 1e9 + 7;        
        int ans = 12;
        long long aba = 6, abc = 6;        
        for(int i = 1; i < n; ++i) {
            long long aba_next = (aba * 3) % M + (abc * 2) % M;
            long long abc_next = (aba * 2) % M + (abc * 2) % M;
            aba = aba_next;
            abc = abc_next;
        }        
        return (aba + abc) % M;                                        
    }
};