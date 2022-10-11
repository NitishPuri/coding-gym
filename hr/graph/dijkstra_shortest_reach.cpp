// https://www.hackerrank.com/challenges/dijkstrashortreach/problem
// graph, hard, dijkstra

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
//#include <utility>
using namespace std;

//#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
#define PRINTVAR(a) 
//#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
#define PRINTIVEC(v) 

typedef vector< map<int, int> > Graph;

void printGraph(Graph& g){
    for(int i = 0; i < g.size(); i++){
        cout << i << " :::: ";
        for(auto j : g[i]){
            cout << "(" << j.first << "," << j.second << ");";
        }
        cout << endl;
    }
}


void processQuery(){
    long n, m;
    cin >> n >> m;
    
    Graph g(n+1);
    for(long i = 0; i < m; i++){
        long u, v, w;
        cin >> u >> v >> w;
        if((g[u].find(v) == g[u].end()) || g[u][v] > w){
            g[u][v] = w;
            g[v][u] = w;            
        }
    }
    
    //printGraph(g);
    
    int s;
    cin >> s;
        
    queue<int> bfsq;
    vector<int> dist(n+1, -1);
    PRINTIVEC(dist);
    bfsq.push(s);
    dist[s] = 0;
    PRINTIVEC(dist);
    while(!bfsq.empty()){
        int v = bfsq.front();
        bfsq.pop();
        PRINTVAR(v);
//        for(int i = 0; i < g[v].size(); i++){
        for(auto i : g[v]){
            int u = i.first;
            int new_dist = dist[v] + i.second;
            PRINTVAR(u);
            PRINTVAR(new_dist);
            if((dist[u] == -1) || (dist[u] > new_dist)){
                bfsq.push(u);
                dist[u] = new_dist;
                PRINTIVEC(dist);
            }
        }
    }
    
    for(int i = 1; i < n+1; i++){
        if(i == s) continue;
        
        cout << dist[i] << ' ';
    }
    
    cout << endl;
    
    
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        processQuery();
    }
    return 0;
}
