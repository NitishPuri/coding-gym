// https://leetcode.com/problems/rotting-oranges/

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct pair_hash {
    template<class T1,class T2>
    std::size_t operator() (const std::pair<T1, T2> &p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_set<pair<int, int>, pair_hash> fresh;
        
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    fresh.insert({i, j});
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if(fresh.empty()) return 0;
        
        auto add_to_queue = [&](int x, int y){
            if(0 <= x && x < m && 0 <= y && y < n && grid[x][y] == 1) {
                grid[x][y] = 2;
                q.push({x, y});
                fresh.erase({x, y});
                return 1;
            }
            return 0;
        };
        
        int time = 0;
        while(!q.empty()) {
            int size = q.size();            
            for(int i = 0; i < size; ++i) {
                auto r = q.front(); q.pop();                
                add_to_queue(r.first - 1, r.second);
                add_to_queue(r.first + 1, r.second);
                add_to_queue(r.first, r.second - 1);
                add_to_queue(r.first, r.second + 1);                                                
            }
            ++time;
            if(fresh.empty()) return time;
        }
        
        return -1;                                
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> g {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    s.orangesRotting(g);
    return 0;
}
