// https://leetcode.com/problems/shuffle-string/
// easy, array, string

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string r = s;
        for(int i = 0; i < indices.size(); ++i) {
            r[indices[i]] = s[i];
        }
        return r;

        // vector<pair<char, int>> str(s.size());
        // for(int i = 0; i < s.size(); ++i) str[i] = {s[i], indices[i]};        
        // sort(str.begin(), str.end(), [](const auto& p1, const auto& p2){
        //     return (p1.second < p2.second);
        // });        
        // for(int i = 0; i < s.size(); ++i) s[i] = str[i].first;
        // return s;        
    }
};