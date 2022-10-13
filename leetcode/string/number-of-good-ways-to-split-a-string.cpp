// https://leetcode.com/problems/number-of-good-ways-to-split-a-string
// medium, string, dynamic-programming, bit-manipulation

// aacaba -> { a : 4, b: 1, c: 1}
// 0 -> 

#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> left, right;
        for(auto ch : s) right[ch]++;                
        int res = 0;
        for(int i = 0; i < s.length(); ++i) {
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.size() == right.size()) ++res;
        }             
        return res;
    }
};