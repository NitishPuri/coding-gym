// https://leetcode.com/problems/minimum-operations-to-convert-number/
// array, breadth-first-search, medium

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
     
        int x = start;
        int n = nums.size();
        
        queue<int> q;
        q.push(x);
        unordered_set<int> s;
        s.insert(x);
        int num_ops = 1;
        
        auto add_to_queue = [&](int x){
            if(0 <= x && x <= 1000 && s.find(x) == s.end()) {
                q.push(x);                
                s.insert(x);
            }            
        };
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; ++i) {
                auto x = q.front(); q.pop();
                
                for(int j = 0; j < n; ++j) {
                    int t = x + nums[j];
                    if(t == goal) return num_ops;
                    else add_to_queue(t);
                    
                    t = x - nums[j];
                    if(t == goal) return num_ops;
                    else add_to_queue(t);

                    t = x ^ nums[j];
                    if(t == goal) return num_ops;
                    else add_to_queue(t);
                }                
            }                        
            ++num_ops;
        }        
        return -1;                        
    }
};