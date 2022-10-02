// https://leetcode.com/problems/minimum-falling-path-sum/

#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> memo;
    int min_rec(const vector<vector<int>>& matrix, int r, int c) {
        int n = matrix.size();
        if(r == n) {
            return 0;
        }
                
        int res = INT_MAX;
        if(r == -1) {            
            for(int j = 0; j < n; j++) {
                res = min(res, min_rec(matrix, r + 1, j) );
            }
            return res;
        } else {
            if(memo[r][c] != -1) return memo[r][c];
            
            for(int j = max(0, c-1); j <= min(n-1, c+1); j++) {
                res = min(res, matrix[r][j] + min_rec(matrix, r + 1, j) );
            }            
        }
        
        memo[r][c]  = res;
        return res;        
    }
    
//     int min_dp(const vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         for(int r = n-1; r >= 0; r--) {
//             for(int c = 0; c < n; c++) {
//                 if(r == n-1) {
//                     memo[r][c] = matrix[r][c]; continue;
//                 }
//                 int res = INT_MAX;
//                 for(int j = max(0, c-1); j <= min(n-1, c+1); j++) {
//                     res = min(res, matrix[r][j] + memo[r+1][j]);
//                 }
//                 memo[r][c] = res;                
//             }                              
//         }
                              
//         int res = INT_MAX;
//         for(int c = 0; c < n; c++) {
//             res = min(res, memo[0][c]);
//         }
//         return res;
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memo = vector<vector<int>>(matrix.size(), vector<int>(matrix.size(), -1));
        return min_rec(matrix, -1, -1);        
        // return min_dp(matrix);        
    }
};