// https://www.hackerrank.com/challenges/bfsshortreach/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void processQuery(){
    int n, m, s;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1);
    
    for(int i = 0 ; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);        
    }
    
    cin >> s;
    
    vector<int> dist(n+1, -1);
    
    queue<int> bfsq;
    bfsq.push(s);
    dist[s] = 0;
    
    int edgeLength = 6;
    
    while(!bfsq.empty()){
        int v = bfsq.front();
        bfsq.pop();
        for(int i = 0; i < graph[v].size(); i++){
            int v2 = graph[v][i];
            if(dist[v2] == -1){
                bfsq.push(v2);
                dist[v2] = dist[v] + edgeLength;                
            }
        }
    }
    
    for(int i = 1; i < n+1; i++){
        if(i != s){
            cout << dist[i] << ' ';            
        }
    }
    
    cout << endl;
        
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++){
        processQuery();
    }
    
    return 0;
}
