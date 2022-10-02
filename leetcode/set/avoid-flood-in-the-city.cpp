// https://leetcode.com/problems/avoid-flood-in-the-city/

// [1, 0, 2, 3, 0, 1, 2]
// flood = 1,0  2,2  3,3  
// dry_days = 1  4  
// ans = -1  -1  -1  -1  -1  -1  -1

#include <vector>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {        
        vector<int> res(rains.size(), -1);        
        
        map<int, int> flood;
        set<int> dry_days;
        
        for(int i = 0; i < rains.size(); i++) {
            if(rains[i] > 0) {
                if(flood.find(rains[i]) != flood.end()) {
                    auto it = dry_days.lower_bound(flood[rains[i]]);
                    if(it == dry_days.end()) { return {}; }
                    res[*it] = rains[i];
                    dry_days.erase(*it);
                }
                flood[rains[i]] = i;
            } else {
                dry_days.insert(i);
                res[i] = 1;
            }
        }
                        
        return res;                
    }
};