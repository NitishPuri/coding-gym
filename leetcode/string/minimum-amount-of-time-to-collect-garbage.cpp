// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // prefix sum
        for(int i = 1; i < travel.size(); ++i) travel[i] += travel[i-1];
        
        int n = garbage.size();
        int res = 0;
        int last_g = -1, last_p = -1, last_m = -1;
        for(int i = 0; i < n; ++i) {
            res += garbage[i].length();
            last_g = ((garbage[i].find('G') == string::npos) ? last_g : i);
            last_m = ((garbage[i].find('M') == string::npos) ? last_m : i);
            last_p = ((garbage[i].find('P') == string::npos) ? last_p : i);                        
        }   
        
        if(last_g > 0) res += travel[last_g-1];
        if(last_p > 0) res += travel[last_p-1];
        if(last_m > 0) res += travel[last_m-1];
                        
        return res;
    }
};