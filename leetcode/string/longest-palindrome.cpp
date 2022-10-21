// https://leetcode.com/problems/longest-palindrome/
// hash-table, string, greedy

#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(auto ch : s)  m[ch] += 1;
        int count = 0;
        for(auto itr = m.begin(); itr != m.end(); ++itr) count += (itr->second / 2) * 2;        
        return (count < s.length()) ? count + 1 : count;
    }
};