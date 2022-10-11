// https://leetcode.com/problems/repeated-substring-pattern/
// easy, string, string-matching

// "abac aba b acab"
// i = 0
// j = 8
// pattern = 4

#include <string>

using namespace std;
    
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int i = 0, j = 1;
        int pattern = 1;
        while(i < s.length() && j < s.length()) {
            if(s[i] == s[j]) {
                i++; j++;
                if(i == pattern) {
                    i = 0;
                }                                
            } else {
                i = 0;
                pattern++;
                j = pattern;
            }
        }
        
        return (pattern != s.length() && i == 0);
        
    }
};