// https://leetcode.com/problems/baseball-game/
// stack, easy, simulation, array

// 5 10 15

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(auto& op : operations) {
            if(op == "+") {
                auto p_top = s.top(); s.pop();
                auto res = p_top + s.top();
                s.push(p_top);
                s.push(res);                
            } else if(op == "D") {
                s.push(s.top() * 2);
            } else if(op == "C") {
                s.pop();
            } else {
                s.push(stoi(op));
            }
        }
        
        int res = 0;
        while(!s.empty()) {
            res += s.top(); s.pop();
        }
        
        return res;
    }
};