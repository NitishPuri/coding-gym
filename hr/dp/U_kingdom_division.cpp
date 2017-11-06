// https://www.hackerrank.com/challenges/kingdom-division/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& graph, int root, vector<int>& parent, vector<int>& size){
    int count = 1;
    for(int i = 0; i < graph[root].size(); i++){
        int u = graph[root][i];
        
        if(parent[u] != -1) continue;  
        
        parent[u] = root;
        size[u] = dfs(graph, u, parent, size);
        count += size[u];
    }
    
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<vector<int>> g(n+1);
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u, v;        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    
    vector<int> parent(n+1, -1);
    vector<int> size(n+1);
    
    // pick a random root.
    int root = 0;
    parent[root] = 0;
    size[root] = dfs(graph, root, parent, size);
    
    return 0;
}
