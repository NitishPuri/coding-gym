// https://leetcode.com/problems/count-asterisks/
// easy, string

#include <string>

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        
        int count_stars = 0;
        int count_bars = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '|') count_bars++;
            if(s[i] == '*' && count_bars % 2 == 0) count_stars++;            
        }
        return count_stars;        
    }
};