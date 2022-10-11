//  https://www.hackerrank.com/challenges/torque-and-development/problem
// graph, medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

//#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
#define PRINTVAR(a)  

//#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
#define PRINTIVEC(v) 

typedef vector<int> Node;
typedef vector<Node> Graph;

void printGraph(const Graph& g){
    return;
    cout << endl << "Printing graph::" << endl;
    for(int i = 0; i < g.size(); i++){
        cout << i << "  ::  ";
        for(auto e : g[i]){
            cout << e << " , ";           
        }
        cout << endl;
    }    
    cout << "Printing graph::" << endl << endl;    
}

void readGraph(Graph& g, int m){
    for(int i = 0; i < m; i++){
        int c1, c2;
        cin >> c1 >> c2;
        c1--; c2--;
                
        g[c1].push_back(c2);
        g[c2].push_back(c1);        
    }    
}

long long processQuery(){
    int n, m;
    long long cl, cr;
    cin >> n >> m >> cl >> cr;    
    
    Graph g(n);
    
    // read in the graph.
    readGraph(g, m);
    
    // print graph
    printGraph(g);
    
    if(cr >= cl){
        return cl*n;      // build a library at every vertex(city).
    }
        
    long long cost = 0;

    vector<int> conn(n, -1);
    int comp = 0;
    
    for(int i = 0; i < n; i++){
        
        PRINTIVEC(conn)
                    
        if(conn[i] != -1) continue;
                       
        conn[i] = comp;
        cost += cl;

        PRINTVAR(i);
        PRINTVAR(cost);
        
        // Find the connected component using BFS
        queue<int> bfsq;
        bfsq.push(i);
        while(!bfsq.empty()){
            int v = bfsq.front();
            //int v = bfsq.top();
            bfsq.pop();
            PRINTVAR(v);
            for(int j = 0; j < g[v].size(); j++){
                PRINTVAR(j);
                PRINTVAR(g[v][j])
                PRINTVAR(conn[g[v][j]]);
                if(conn[g[v][j]] == -1){
                    bfsq.push(g[v][j]);                
                    conn[g[v][j]] = comp;
                    cost += cr;
                    PRINTVAR(cost);
                }            
            }
        }
        
        comp++;        
    }
    
        
    return cost;     
    PRINTVAR(comp);
    //return (n-(comp))*cr + (comp)*cl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int q;
    
    cin >> q;
    //PRINTVAR(q);
    
    for(int i = 0; i < q; i++){
        cout << processQuery() << endl;
    }
    
    return 0;
}
