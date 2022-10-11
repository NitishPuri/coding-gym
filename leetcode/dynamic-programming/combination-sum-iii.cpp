// https://leetcode.com/problems/combination-sum-iii/
// dynamic-programming, medium, array, backtracking

#include <vector>

using namespace std;

class Solution {
    
    void combinationSum3_rec(int k, int n, vector<int> sol, vector<vector<int>>&res) {        
        if(k == sol.size() && n == 0) {
            res.push_back(sol);
            return;
        }
        if(k <= sol.size() || n <= 0) {
            return;
        }                
        for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {            
            sol.push_back(i);
            combinationSum3_rec(k, n-i, sol, res);
            sol.pop_back();
            
        }        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;        
        vector<int> sol;
        combinationSum3_rec(k, n, sol, ans);                                
        return ans;
    }
};

int main() {
    Solution s;
    auto res = s.combinationSum3(3, 7);
}