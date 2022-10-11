// https://leetcode.com/problems/path-with-maximum-probability/
// medium, graph, priority-queue, shortest-path, graph

// 3 vert
// v[0] = {{1, 0.5}, {2, 0.2}}
// v[1] = {{0, 0.5}, {2, 0.5}}
// v[2] = {{1,0.5}, {0, 0.2}}
// bfs
// frontier(pq) = {{0, 1}} , visited(set) = {}
// extract from frontier -> {0,1}
// traverse neighbors of 0 -> 1 , 2 
// frontier = {{1, 0.5}, {2, 0.2}} , visited {0}
// extract -> {1, 0.5}
// neighbors of 1 -> 2
// frontier = {{2, 0.25}, {2, 0.2}} , visited = {0, 1}
// extract -> 2, 0.25
// neighbors of 2 not in visited -> {}

#include <vector>
#include <queue>
#include <set>

using namespace std;
struct Edge {
    int end;  // other end of edge.
    int index;  // index into successProb vector.
};
struct Vert {
    int index;  // index of vertex
    double prob_to_reach;    
};

bool operator < (const Edge& e1, const Edge& e2) {
    return e1.end < e2.end;
}

bool operator < (const Vert& v1, const Vert& v2) {
    return v1.prob_to_reach < v2.prob_to_reach;
} 

class Solution {

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // create adjacency set         
        vector<set<Edge>> vert(n, set<Edge>());     // Space = O(n + e)
        for(int i = 0; i < edges.size(); i++) {     // O(e)
            vert[edges[i][0]].insert({edges[i][1], i});   // O(log(n))
            vert[edges[i][1]].insert({edges[i][0], i});
        }
        
        // bfs
        priority_queue<Vert> frontier;
        set<int> visited;
        frontier.push({start, 1});
        while(!frontier.empty()) {      // O(e)
            auto top = frontier.top(); frontier.pop();  // O(log(e))
            if(top.index == end) {
                return top.prob_to_reach;
            }
            auto& edges = vert[top.index];   // 
            for(auto itr = edges.begin(); itr != edges.end(); itr++) {   // 
                if(visited.find(itr->end) == visited.end()) {                    // log(n)
                    frontier.push({itr->end, succProb[itr->index] * top.prob_to_reach});
                }                
            }
            
            visited.insert(top.index);
        }      
        return 0.0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {0,2}};
    vector<double> succProb {0.5, 0.5, 0.2};
    s.maxProbability(3, edges, succProb, 0, 2);
}


