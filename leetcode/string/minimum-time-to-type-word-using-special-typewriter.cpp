// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
// string, greedy, easy

#include <string>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {                
        char curr = 'a';
        int res = 0;
        for(char ch : word) {
            res += min( (ch - curr + 26) % 26, (curr - ch + 26) % 26) + 1;
            curr = ch;
        }        
        return res;
    }
};