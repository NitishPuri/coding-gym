// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// medium, array, hash-table, counting

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        long res = 0;
        
        // n^2         
        // for(int i = 0; i < time.size(); i++) {
        //     for(int j = i+1; j < time.size(); j++) {
        //         if( (time[i] + time[j]) % 60 == 0) {
        //             res++;
        //         }
        //     }
        // }
        
        map<int, int> m;
        for(int i = 0; i < time.size(); i++) {
            int num = time[i] % 60;
            auto itr = m.find(num);
            if(itr == m.end()) {
                m[num] = 1;                
            } else {
                itr->second++;
            }            
        }
        
        for(int i = 0; i < time.size(); i++) {
            int num = (60 - (time[i] % 60)) % 60;
            auto itr = m.find(num);
            if(itr != m.end()) {
                res += itr->second;
                if(num == 30) res--;
                if(num == 0) res--;
            }
        }
                        
        return res/2;
    }
};