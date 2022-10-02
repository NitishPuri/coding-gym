// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// a = 61, t = 116, e = 101, 
// "sea,eat" = min(61 + 'se,eat' , 116 + 'sea,ea')

// 'se,eat' = min (101 + 's,eat', 116 + 'se,ea')
// 'sea,ea' = min ('se,ea', 'sea,e')

// 's,eat' = min ('s' + 's,eat', 't' + 'se,ea')
// 'se,eat' = min ('e' + 's,eat', 't' + 'se,ea')




//    s    e     a
//e   
//a
//t

#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<vector<int>> memo;
    int min_rec(const string& s1, const string& s2 ,int i, int j) {
        if(memo[i][j] != -1) return memo[i][j];
        
        int res = 0;
        if(i == 0) {
            res = (j == 0) ? 0 : s2[j-1] + min_rec(s1, s2, i, j-1);
        }
        else if(j == 0) {
            res = s1[i-1] + min_rec(s1, s2, i-1, j);
        }
        else if(s1[i-1] == s2[j-1]) {
            res = min_rec(s1, s2, i-1, j-1);
        } else {
            res = min(s1[i-1] + min_rec(s1, s2, i-1, j), s2[j-1] + min_rec(s1, s2, i, j-1));            
        }
        
        memo[i][j] = res;
        return res;
    }
    
    int min_dp(const string& s1, const string& s2) {
        memo[0][0] = 0;        
        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                int res = 0;
                if(i == 0) {
                    res = (j == 0) ? 0 : s2[j-1] + memo[i][j-1];
                }
                else if(j == 0) {
                    res = s1[i-1] + memo[i-1][j];
                }
                else if(s1[i-1] == s2[j-1]) {
                    res = memo[i-1][j-1];
                } else {
                    res = min(s1[i-1] + memo[i-1][j], s2[j-1] + memo[i][j-1]);
                }
                memo[i][j] = res;                
            }
        }
        return memo[s1.length()][s2.length()];                              
    }

public:
    int minimumDeleteSum(string s1, string s2) {
         memo = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length()+1, -1));
         // return min_rec(s1, s2, s1.length(), s2.length());
         return min_dp(s1, s2);
    }
};