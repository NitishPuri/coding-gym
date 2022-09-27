// https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1391/

#include <vector>
#include <set>
#include <queue>
using namespace std;

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation: 
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        set<int> visited;
        visited.insert(0);        
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int curr = q.front(); q.pop();            
            for(auto key : rooms[curr]) {
                if(visited.find(key) == visited.end()) {
                    q.push(key);
                    visited.insert(key);
                }
            }
        }
        
        return visited.size() == rooms.size();
        
    }
};