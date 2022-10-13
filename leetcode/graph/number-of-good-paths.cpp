// https://leetcode.com/problems/number-of-good-paths
// array, tree, union-find, graph

#include <vector>

using namespace std;

class Solution {
    void dfs(vector<int>& vals, vector<vector<int>>& adj, int start, int parent, int curr, int& count, vector<bool>& visited) {
        
        for(int i = 0; i < adj[curr].size(); ++i) {
            int neighbor = adj[curr][i];
            if(neighbor == parent) continue;
            if(vals[start] < vals[neighbor]) continue;
            if(vals[start] == vals[neighbor]) {
                count++;
                visited[neighbor] = true;
            }
            dfs(vals, adj, start, curr, neighbor, count, visited);
        }                
    }
    
    
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {    // O(n^2)             
        
        int n = vals.size();        
        
        vector<vector<int>> adj(n, vector<int>());  // O(n)
        for(int i = 0; i < edges.size(); ++i) {    // O(n)
            adj[edges[i][0]].push_back(edges[i][1]);   // O(1)
            adj[edges[i][1]].push_back(edges[i][0]);   // O(1)
        }
        
        int res = n;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i) {
            if(visited[i]) continue;
            int count = 1;
            dfs(vals, adj, i, -1, i, count, visited);
            visited[i] = true;
            res += count * (count - 1) / 2;
        }  
        
        return res;
        
    }
};