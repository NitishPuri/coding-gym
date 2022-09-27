// https://leetcode.com/problems/minimum-time-visiting-all-points/

#include <vector>

using namespace std;

// Input: points = [[1,1],[3,4],[-1,0]]
// Output: 7
// Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
// Time from [1,1] to [3,4] = 3 seconds 
// Time from [3,4] to [-1,0] = 4 seconds
// Total time = 7 seconds

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        auto prev = points[0];
        int res = 0;
        for(int i = 1; i < points.size(); i++) {
            auto curr = points[i];                    
            res += max(abs(curr[0] - prev[0]) , abs(curr[1]- prev[1]) );
            prev = curr;
        }
        
        return res;
    }
};