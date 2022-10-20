// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// string, stack, tree, binary-tree

#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        int curr = 0, n = preorder.length();        
        
        auto read_next = [&](){
            if(preorder[curr] == '#') {
                curr += 2;      // skip "#,"
                return -1;
            } 
            
            int num = 0;
            while(curr < n && '0' <= preorder[curr] && preorder[curr] <= '9') {
                num = num * 10 + (preorder[curr] - '0');
                ++curr;
            }
            curr += 1;      // slip ','            
            return num;            
        };
        
        stack<pair<int, int>> st;
        st.push({read_next(), 0});
        if(st.top().first == -1) {
            if(curr >= n) return true;
            else return false;
        }
        while(curr <= n && !st.empty()) {
            while(!st.empty() && st.top().second == 2) st.pop();
            if(st.empty()) return false;
            auto next = read_next();
            if(next == -1) {  // encountered null node.
                st.top().second += 1;
            } else {
                st.top().second += 1;
                st.push({next, 0});     // 0 => no children have been processed.
            }                    
        }        
        while(!st.empty() && st.top().second == 2) st.pop();
                
        if(curr < n || !st.empty()) return false;
        
        
        return true;
    }
};