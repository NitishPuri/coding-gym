// https://leetcode.com/problems/count-different-palindromic-subsequences/
// string, dynamic-programming, hard

#include <string>
using namespace std;

class Solution {
    
    int MOD = 1e9 + 7;
    int memo[1001][1001][4];
    
    int dp(const string& s, int l, int r, int a) {        
        if(l > r) return 0;
        
        char ch =  'a' + a;
        if(l == r) return (s[l] == ch);
        
        if(memo[l][r][a] != -1) return memo[l][r][a];
        
        int res = 0;
        if(s[l] == ch && s[r] == ch) {
            res = 2;
            for(int i = 0; i < 4; ++i) {
                res = (res + dp(s, l + 1, r - 1, i)) % MOD;
            }                         
        } else {
            res = (res + dp(s, l+1, r, a)) % MOD;
            res = (res + dp(s, l, r-1, a)) % MOD;
            res = (res - dp(s, l + 1, r - 1, a)) % MOD;
            if(res < 0) res += MOD;
        }
        
        memo[l][r][a] = res;
        
        return res;                
    }
public:
    int countPalindromicSubsequences(string s) {
        int ans = 0;
        memset(&memo, -1, sizeof(memo));
                
        for(int i = 0; i < 4; ++i) {
            ans  = (ans + dp(s, 0, s.length() - 1, i)) % MOD;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.countPalindromicSubsequences("bccb");
    return 0;
}
