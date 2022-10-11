// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// easy, string, stack

#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {        
        string res;
        res.push_back(s[0]);
        for(int j = 1; j < s.length(); ++j) {
            if(s[j] == res.back()) {
                res.pop_back();
            } else {
                res.push_back(s[j]);
            }
        }        
        return res;
        
    }
};