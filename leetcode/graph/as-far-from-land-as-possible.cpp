// https://leetcode.com/problems/as-far-from-land-as-possible/
// array, dynamic-programming, breadth-first-search, matrix

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {        
        int n = grid.size();
        queue<pair<int, int>> q;        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        if(q.size() == n*n) {
            return -1;
        }
        
        auto add_to_queue = [&](int i, int j) {
            if(0 <= i && i <= n-1 && 0 <= j && j <= n-1 && grid[i][j] == 0) {
                q.push({i, j});
                grid[i][j] = 1;
            }
        };
        
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto cell = q.front(); q.pop();
                add_to_queue(cell.first - 1, cell.second);
                add_to_queue(cell.first + 1, cell.second);
                add_to_queue(cell.first, cell.second - 1);
                add_to_queue(cell.first, cell.second + 1);                
            }            
            ++level;
        }
        
        return level - 1;                                                
    }
};