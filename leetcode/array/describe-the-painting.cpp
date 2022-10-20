// https://leetcode.com/problems/describe-the-painting/
// medium, prefix-sum, array

// (1, 7, 9), (1, 4, 5), , (4, 7, 7)
// 

// cs = 4, ce = 7

// (1, 4, 14) , (4, 7, 9)


// m : {1, 14} , (4, 2)  (7, -2), 

// (1, 4, 14), (4, 7, 16)

#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> m;
        for(auto& s : segments) {
            m[s[0]] += s[2];
            m[s[1]] -= s[2];
        }        
        vector<vector<long long>> v;        
        auto itr = m.begin();
        auto curr_start = itr->first;
        auto curr_sum = itr->second;
        ++itr;
        for(; itr != m.end(); ++itr) {
            if(curr_sum)
                v.push_back({curr_start, itr->first, curr_sum});
            curr_start = itr->first;
            curr_sum += itr->second;
        }
        return v;
    }
};