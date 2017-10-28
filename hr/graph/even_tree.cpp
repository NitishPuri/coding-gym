// https://www.hackerrank.com/challenges/even-tree/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*struct Node{
    vector<Node&> children;
    Node& parent;
    
    int id;
};*/

int dfs(vector<vector<int>> & graph, int root, vector<int>& parent, vector<int>& size){
    int count = 1;       
    for(int i = 0; i < graph[root].size(); i++){
        int v = graph[root][i];
        if(parent[v] == -1){
            parent[v] = root;
            size[v] = dfs(graph, v, parent, size); 
            count += size[v];                      
        }
    }
        
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1);
    vector<int> size(n+1, 0);
    vector<int> parent(n+1, -1);
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);                
    }
    
    int root = 1;    
    
    parent[root] = 0;
    size[root] = dfs(graph, root, parent, size);
    
    
    int canBreak = 0;
    
    queue<int> bfsq;
    bfsq.push(root);
    while(!bfsq.empty()){
        int v = bfsq.front();
        bfsq.pop();
        for(int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i];
            if(u != parent[v]){ // skip parent
                bfsq.push(u);
                if(size[u]%2 == 0){     // can break
                    canBreak++;
                    size[v] -= size[u];
                    //cout << "Can break :: (" << v << "," << u << ")" << endl;
                }                    
            }
        }
    }
    
    cout << canBreak;
                                
    return 0;
}
