// https://www.hackerrank.com/challenges/the-story-of-a-tree/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
//#define PRINTVAR(a) 
#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
//#define PRINTIVEC(v) 

int dfs(const vector<vector<int>>& graph, int root, vector<int>& parent, vector<int>& size){
    int count = 1;
    for(int i = 0; i < graph[root].size(); i++){
        int v = graph[root][i];
        if(parent[v] == -1){
            parent[v] = root;
            //PRINTIVEC(parent);
            size[v] = dfs(graph, v, parent, size);
            count += size[v];
        }
    }
    
    return count;
}

void calcWins(const vector<vector<int>>& graph, int root, int qc, int qp, vector<int>& parent ,
              vector<int>& correct, bool winning){
    
    if(winning){
        correct[root] += 1;
    }
    
    //visited[child] = true;
    
    for(int i = 0; i < graph[root].size(); i++){
        int v = graph[root][i];
            
        if(v != parent[root]){
            if((root == qc) && (v == qp)){
                calcWins(graph, v, qc, qp, parent, correct, true);
            }
            else if((root == qp) && (v == qc)){
                // dont need to go there.
                //calcWins(graph, v, qc, qp, parent, correct, false);
            }
            else{
                calcWins(graph, v, qc, qp, parent, correct, winning);
            }            
        }            
    }
}

int gcd(int u, int v){
    while(v != 0){
        int r = u % v;
        u = v;
        v = r;
    }
    
    return u;
}

void playGame(){
    int n;      // number of nodes.
    cin >> n;
    //PRINTVAR(n);
    
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // number of guesses, required score.
    int g, k;
    cin >> g >> k; 
    //PRINTVAR(g);
    //PRINTVAR(k);
    
    //map<int, int> queries;
    vector<pair<int, int>> queries(g);
    
    for(int i = 0; i < g; i++){
        int u, v;
        cin >> u >> v;      // guess parent(v) = u
        queries[i] = make_pair(v, u);                       
    }
    
    int wins = 0;
    
    vector<int> parent(n+1, -1);        
    vector<int> size(n+1, 0);
    //PRINTVAR(i);
    //PRINTIVEC(parent);
    int i = 1;
    parent[i] = 0;
    dfs(graph, i, parent, size);
    //PRINTIVEC(parent);
    //PRINTIVEC(size);
        
    vector<int> correct(n+1, 0);
        
    // check all the queries
    for(auto q : queries){
        bool winning = (parent[q.first] == q.second);
        calcWins(graph, i, q.first, q.second, parent, correct, winning);            
    }
        
//        PRINTVAR(correct);
        //PRINTIVEC(correct);
            
    for(auto c : correct){
        if(c >= k){
            wins++;
        }
    }
            
    //PRINTVAR(wins);
    
    int f = gcd(wins, n);
    cout << (wins/f) << '/' << (n/f) << endl;        
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;       // number of games
    
    for(int i = 0; i < q; i++){
        playGame();
    }
    return 0;
}
