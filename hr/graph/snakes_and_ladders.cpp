// https://www.hackerrank.com/challenges/the-quickest-way-up/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;


void printMap(map<int, int>& m){
    for(auto i : m){
        cout << i.first << ":::" << i.second << endl;
    }
}
void processQuery(){
    
    int l, s;
    map<int, int> m;
    m.clear();
    
    cin >> l;
    for(int i = 0; i < l; i++){
        int u, v;
        cin >> u >> v;
        m[u] = v;
    }
    
    cin >> s;
    for(int i = 0; i < s; i++){
        int u, v;
        cin >> u >> v;
        m[u] = v;
    }
    
    //printMap(m);\
        
    vector<vector<int>> graph(101);
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 7; j++){
            int k = i+j;
            if(m.find(k) != m.end()){
                //if(m[k] == 0)
                k = m[k];
            }
            graph[i].push_back(k);            
        }
    }
        
    int start = 1, end = 100;
    vector<int> dist(101, -1);
    queue<int> bfsq;
    bfsq.push(start);
    dist[start] = 0;
    while(!bfsq.empty()){
        int v = bfsq.front();
        //cout << "Processing vertex :: " << v << " :: " << dist[v] << endl;
        bfsq.pop();
        
        for(int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i];
            if(dist[u] == -1){
                bfsq.push(u);
                dist[u] = dist[v] + 1;
            }
        }
        
        if(dist[100] != -1) break;
    }
    
    
    cout << dist[100] << endl;
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
