// https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
// breadth-first-search, graph, matrix, array, hard

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node {
    int r, c;
    bool h;
};

bool operator == (const Node& l, const Node& other) {
    return (l.c == other.c) && (l.r == other.r) && (l.h == other.h);
}

struct node_hash {
    size_t operator() (const Node& l) const {
        return hash<int>() (l.r) ^ hash<int>()(l.c) ^ hash<bool>() (l.h);
    }
};

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        queue<Node> q;
        unordered_set<Node, node_hash> visited;
        q.push({0, 1, true});
        visited.insert({0, 1, true});
        int moves = 0;

        auto add_node = [&](const Node& node){
            if(visited.find(node) == visited.end()) {
                q.push(node);
                visited.insert(node);
            }
        };
        while(!q.empty()) {
            
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto node = q.front(); q.pop();
                
                if(node.r == n - 1 && node.c == m - 1 && node.h == true) {
                    return moves;
                }
                                
                // can move right
                if(node.c < n - 1 && grid[node.r][node.c+1] == 0) {
                    if(node.h || grid[node.r-1][node.c+1] == 0) {
                        add_node({node.r, node.c+1, node.h});
                    }
                }
                
                // can move down
                if(node.r < m - 1 && grid[node.r + 1][node.c] == 0) {
                    if(!node.h || grid[node.r + 1][node.c - 1] == 0) {
                        add_node({node.r + 1, node.c, node.h});
                    }
                }
                
                // can rotate
                if(node.h) {
                    if(node.r < m - 1 && grid[node.r + 1][node.c - 1] == 0 && grid[node.r + 1][node.c] == 0) {
                        add_node({node.r+1, node.c-1, !node.h});
                    }                    
                }
                else {
                    if(node.c < n - 1 && grid[node.r][node.c+1] == 0 && grid[node.r-1][node.c+1] == 0) {
                        add_node({node.r - 1, node.c + 1, !node.h});
                    }                                        
                }                
            }
            
            ++moves;
                        
        }
        
        return moves;                
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid {
        {0,0,0,0,0,0,0,0,0,1},
        {0,1,0,0,0,0,0,1,0,1},
        {1,0,0,1,0,0,1,0,1,0},
        {0,0,0,1,0,1,0,1,0,0},
        {0,0,0,0,1,0,0,0,0,1},
        {0,0,1,0,0,0,0,0,0,0},
        {1,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0}
    };

    s.minimumMoves(grid);
    return 0;
}
