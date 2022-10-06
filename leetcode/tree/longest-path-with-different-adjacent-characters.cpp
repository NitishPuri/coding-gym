// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

#include <vector>
#include <queue>
#include <string>
using namespace std;

// a A

// a A

class Solution {
// My solution.    
//     int longest_rec(const vector<vector<int>>& children, const string& s,int root, int& ans) {
//         auto& c = children[root];
//         if(c.empty()) return 1;
        
//         int res_tot = 1;
        
//         priority_queue<int> pq;
//         for(int i = 0; i < c.size(); ++i) {
//             auto res = longest_rec(children, s, c[i], ans);            
//             if(s[root] != s[c[i]]) {
//                 pq.push(res);
//             }
//             ans = max(ans, res);
//             // res_tot = max(res_tot, res);
//         }
        
//         int max_elements = 2;
//         while(max_elements && !pq.empty()) {
//             res_tot += pq.top(); pq.pop();
//             --max_elements;
//         }
        
//         return res_tot;     
//     }
    
// public:
//     int longestPath(vector<int>& parent, string s) {
//         int n = parent.size();
//         vector<vector<int>> children(n, vector<int>());
//         for(int i = 1; i < n; ++i) {
//             children[parent[i]].push_back(i);
//         }
//         int ans = -1;
//         auto res = longest_rec(children, s, 0, ans);
//         ans = max(ans, res);
//         return ans;
//     }

// Copied from https://leetcode.com/problems/longest-path-with-different-adjacent-characters/discuss/1955433/JavaC%2B%2BPython-DFS-on-Tree    
public:    
    int longestPath(vector<int>& parent, string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> children(n, vector<int>());
        for (int i = 1; i < n; ++i)
            children[parent[i]].push_back(i);
        dfs(children, s, res, 0);
        return res;
    }

    int dfs(vector<vector<int>>& children, string& s, int& res, int i) {
        int big1 = 0, big2 = 0;
        for (int& j : children[i]) {
            int cur = dfs(children, s, res, j);
            if (s[i] == s[j]) continue;
            if (cur > big2) big2 = cur;
            if (big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }    
};



int main(int argc, char const *argv[])
{
    Solution s;
    s.longestPath({-1,0,0,1,1,2}, "abacbe");
    return 0;
}
