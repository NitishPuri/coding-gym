// https://leetcode.com/problems/array-of-doubled-pairs/
// medium, array, hash-table, greedy, sorting

// 4 -2 2 -4
// -4: 1, -2: 1, 2: 1, 4: 1

// i = 0 -> a[1] = 2 * a[0]
// i = 1 -> a[3] = 2 * a[2]
// i = 2 -> a[5] = 2 * a[4]

#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> count_pos, count_neg;
        for(int a : arr) {
            if(a >= 0) count_pos[a]++;
            else count_neg[-a]++;
        }
        
        
        for(auto itr = count_pos.begin(); itr != count_pos.end(); ++itr) {
            if(itr->second == 0) {
                continue;
            }
                        
            auto itr2 = count_pos.find(2 * itr->first);
            if(itr2 == count_pos.end()) return false;
            if(itr2->second < itr->second) return false;

            itr2->second -= itr->second;
            itr->second = 0;            
        }        
        
        for(auto itr = count_neg.begin(); itr != count_neg.end(); ++itr) {
            if(itr->second == 0) {
                continue;
            }
                        
            auto itr2 = count_neg.find(2 * itr->first);
            if(itr2 == count_neg.end()) return false;
            if(itr2->second < itr->second) return false;

            itr2->second -= itr->second;
            itr->second = 0;            
        }        
        
        return true;
    }
};