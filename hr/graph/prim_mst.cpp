//  https://www.hackerrank.com/challenges/primsmstsub/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
//#define PRINTVAR(a) 
#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
//#define PRINTIVEC(v) 


struct Edge{
    int u;
    int v;
    int w;
    bool operator<(const Edge& rhs) const{
        return (w > rhs.w);
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    
    cin >> n >> m;
    
    vector<map<int, int>> g(n+1);
    
    for(int i = 0; i < m ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if((g[u].find(v) == g[u].end()) || (g[u][v] > w)){
            g[u][v] = w;
            g[v][u] = w;            
        }                
    }
    
    int s;
    cin >> s;
    
    priority_queue<Edge> eq;
    vector<bool> conn(n+1, false);
    
    for(auto i : g[s]){
        int v = i.first;
        int w = i.second;
        eq.push(Edge{s, v, w});
    }
    conn[s] = true;
    
    int mst = 0;
    
    //bfsq.push(s);
    while(!eq.empty()){
        Edge e = eq.top();
        eq.pop();
        
        int u;
        if(!conn[e.u]){
            u = e.u;
        }
        else if(!conn[e.v]){
            u = e.v;
        }
        else{
            continue;
        }
                
        conn[u] = true;                
        mst += e.w;
        
        for(auto i : g[u]){
            int v = i.first;
            int w = i.second;
            
            if(!conn[v]){
                eq.push(Edge{u, v, w});
            }
        }        
    }
    
    cout << mst;
    
    
    return 0;
}
