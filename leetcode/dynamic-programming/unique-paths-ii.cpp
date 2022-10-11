// https://leetcode.com/problems/unique-paths-ii/
// medium, array, dynamic-programming, matrix

#include <map>
#include <vector>

using namespace std;

class Solution {
    map<pair<int, int> , int> memo;
    int paths_rec(vector<vector<int>>& g, int i, int j) {
        int m = g.size(), n = g[0].size();
        if(i == m || j == n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(g[i][j] == 1) return 0;
        auto itr = memo.find({i, j});
        if(itr != memo.end()) return itr->second;
        int ans = paths_rec(g, i + 1, j) + paths_rec(g, i, j+1); 
        memo[{i, j}] = ans;
        return ans;
    }
    int paths_dp(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                dp[i][j] += (g[i][j] == 1 ? 0 : dp[i+1][j] + dp[i][j+1]); 
            }
        }
        return dp[0][0];
    }    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {        
        int m = g.size(), n = g[0].size();
        if(g[m-1][n-1] == 1) return 0;
        // return paths_rec(g, 0, 0);       
        return paths_dp(g);
    }
};