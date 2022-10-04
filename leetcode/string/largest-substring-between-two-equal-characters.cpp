// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

#include <string>
#include <array>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        array<pair<int, int>, 26> f;
        f.fill({INT_MAX, INT_MIN});
        
        for(int i = 0; i < s.length(); ++i) {
            auto c = s[i];
            f[c - 'a'].first = min(f[c - 'a'].first, i);
            f[c - 'a'].second = max(f[c - 'a'].second, i);
        }
        
        int res = INT_MIN;
        for(int i = 0; i < 26; i++) {
            if(f[i].first == INT_MAX || f[i].second == INT_MIN) continue;
            res = max(res, f[i].second - f[i].first - 1);
        }
        
        return res;
        
        
    }
};