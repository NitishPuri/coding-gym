// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
// string, counting, easy, hash-table

#include <string>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int d = 0;
        for(int i = 0; i < s1.length(); ++i) {
            if(s1[i] != s2[i]) ++d;
        }        
        return (d == 0 || d == 2);        
    }
};