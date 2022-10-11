// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
// hard, array, math, sorting, priority-queue, number-theory

// 2 3 2 4 3 -> 2: 2, 3: 2, 4: 1
// 9 6 9 3 15 -> 1, 3

#include <map>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) m[nums[i]]++;
        
        int gcd_all = (numsDivide.size() == 1 ? numsDivide[0] :  gcd(numsDivide[0], numsDivide[1]));
        for(int i = 2; i < numsDivide.size(); ++i) {
            gcd_all = gcd(gcd_all, numsDivide[i]);
        }
                    
        auto itr = m.begin();
        int ans = 0;
        while(itr != m.end()) {
            // int i = 0;
            // for(; i < numsDivide.size(); ++i) {
            //     if(numsDivide[i] % itr->first != 0) {
            //         break;
            //     }
            // }
            // if(i == numsDivide.size()) {
            //     return ans;
            // }
            
            if(gcd_all % itr->first == 0) return ans;
            
            ans += itr->second;                
            ++itr;
        }
        
        return -1;                                        
    }
};