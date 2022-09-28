// https://leetcode.com/problems/longest-uncommon-subsequence-i/

#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {        
        if(a.length() != b.length()) return max(a.length(), b.length());
        if(a == b) return -1;        
        return a.length();                                        
    }
};