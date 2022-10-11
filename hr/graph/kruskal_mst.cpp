// https://www.hackerrank.com/challenges/kruskalmstrsub/problem
// graph, medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
//#define PRINTVAR(a) 
#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
//#define PRINTIVEC(v) 

struct Edge{
            
    int u;
    int v;
    int w;    
    
    bool operator<(const Edge& rhs) const {
        if(w == rhs.w){
            return ((u + v + w) > (rhs.u + rhs.v + rhs.w));
        }
        
        return (w > rhs.w);
    }
};

int getComp(vector<int> & comps, int index){
    while(comps[index] != index){
        index = comps[index];
    }
    return index;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    
    cin >> n >> m;      // input graph size
    
    vector<int> comp(n+1);      // somponent graph for the mst
    vector<int> size(n+1, 1);
    for(int i = 1; i < n+1; i++){
        // initialize all the vertices belonging to their own components
        comp[i] = i;       
    }
    
    priority_queue<Edge> q;    // priority queue for edges.
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;         // input the edges.
        
        q.push(Edge{u, v, w});
    }
    
    int numComp = n;
    int mst = 0;
    while(!q.empty()){              // for all the edges starting from the shortest
        Edge e = q.top();
        q.pop();
        
//        PRINTVAR(e.u);
//        PRINTVAR(e.v);
//        PRINTVAR(e.w);        
        
        // find out components for the two vertices.
        int u = getComp(comp, e.u);     
        int v = getComp(comp, e.v);
        
        // if they belong to the same component, skip,..
        if(u == v) continue;
        
        // if they belong to different components, join.
        if(size[u] < size[v]){
            size[v] += size[u];
            comp[u] = v;
        }
        else{
            size[u] += size[v];
            comp[v] = u;
        }
        
        mst += e.w;
        
        numComp--;
        
        if(numComp == 1){
            break;
        }                               
    }
    
    cout << mst;
    
    return 0;
}
