// https://leetcode.com/problems/maximum-ice-cream-bars
// medium, greedy, sorting


// 1 6 3 1 2 5
// 1 1 2 3 5 6
// 1 2 4 7 12 18

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());        
        int cost = 0;
        for(int i = 0; i < costs.size(); ++i) {
            cost += costs[i];
            if(cost > coins) return i;
        }
        return costs.size();
    }
};
