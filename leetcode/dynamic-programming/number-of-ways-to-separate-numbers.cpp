// https://leetcode.com/problems/number-of-ways-to-separate-numbers/
// string, dynamic-programming, suffix-array, hard
// 327, 0, 0
// 3, (27, 1, 3) + 32 , (7, 2, 32)

#include <vector>
#include <string>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    bool compare(const string& num, int i, int j, int k, int l) {
        // return int(num[i:j]) >= int(num[k:l])    
        
        if(j - i == l - k) {
            int p = 0;
            while(p <= j - i) {
                if(num[i + p] == num[k + p]) {
                    ++p;
                    continue;
                }
                return num[i + p] > num[k + p];
            }
            return true;            
            
            // return memcmp(&num[i],&num[k],j - i + 1) <= 0;
        }
        
        return (j - i > l - k);        
    }
    
    int dp(const string& num, int i, int k) {                
        int n = num.length();
        if(i == n) return 1;
        if(num[i] == '0') return 0;
        
        if(memo[i][k] != -1) return memo[i][k];
        
        int j = i;
        // long long curr = 0;
        int res = 0;
        
        while(j < n) {
            // curr = (((curr * 10) % MOD) + (num[i] - '0')) % MOD;            
            if(compare(num, i, j, k, i - 1)) {
            // if(curr >= min) {
                res = (res + dp(num, j + 1, i)) % MOD;
            }            
            ++j;                
        }
        
        memo[i][k] = res; 
        
        return res;        
    }
    
public:
    int numberOfCombinations(string num) {
        int n = num.length();
        memo = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return dp(num, 0, 0);                        
    }
};