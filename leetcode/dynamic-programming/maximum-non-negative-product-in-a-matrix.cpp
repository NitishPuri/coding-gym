// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

// -1  -2  -3
// -2  -3  -3
// -3  -3  -2

// x   .   0   1   2  
// .               0
// 0      -36  36 -18
// 1  0    36 -18  6
// 2  0   -18  6  -2


//-1 -2 1
// 1 -2 1
// 5 -4 1

// x   0   1   2
// 0   16  -16  1
// 1   8   8   1
// 2  -20  -4  1

// x   0   1   2
// 0   16  -16  1
// 1   8   8   1
// 2  -20  -4  1

// (a * b) % d == (a % d) * (b % d)
// a = pd + r , b = qd + s
// a * b = pqdd + psd + qrd + rs

// -a % d = 

#include <vector>

using namespace std;


class Solution {
//     pair<long long, long long> min_rec(const vector<vector<int>>& grid, int m, int n) {
        
//         if(m == grid.size() -1 && n == grid[0].size() - 1) return { grid[m][n], grid[m][n] };
//         long M = 1e9 + 7;
        
//         if(grid[m][n] == 0) return {0, 0};
                            
//         long long res_min = LLONG_MAX, res_max = LLONG_MIN;
//         if(m == grid.size() - 1) {
//             auto res2 = min_rec(grid, m, n+1);
//             res_min = grid[m][n] * res2.first;
//             res_max = grid[m][n] * res2.second;
//         } else if(n == grid[0].size() - 1) {
//             auto res1 = min_rec(grid, m+1, n);
//             res_min = grid[m][n] * res1.first;
//             res_max = grid[m][n] * res1.second;            
//         } else {
//             auto res1 = min_rec(grid, m+1, n);
//             auto res2 = min_rec(grid, m, n+1);            
//             if(grid[m][n] >= 0) {
//                 res_min = min(res1.first , res2.first) * grid[m][n];
//                 res_max = max(res1.second , res2.second) * grid[m][n];
//             } else {
//                 res_min = max(res1.second , res2.second) * grid[m][n];
//                 res_max = min(res1.first , res2.first) * grid[m][n];            
//             }            
//         }
        
//         return {res_min % M, res_max % M};
//     }
    
    int max_dp(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), M = 1e9 + 7;
        vector<vector<long long>> mx(m, vector<long long>(n, 0)), mn(m, vector<long long>(n, 0));
        mx[0][0] = mn[0][0] = grid[0][0];
        
        for(int i = 1; i < m; ++i) {
            mn[i][0] = mx[i][0] = mx[i-1][0]*grid[i][0];
        }
        for(int i = 1; i < n; ++i) {
            mn[0][i] = mx[0][i] = mx[0][i-1]*grid[0][i];
        }
        
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(grid[i][j] < 0) {
                    mx[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                    mn[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];
                } else {
                    mn[i][j] = min(mn[i-1][j], mn[i][j-1]) * grid[i][j];
                    mx[i][j] = max(mx[i-1][j], mx[i][j-1]) * grid[i][j];                    
                }
            }
        }
        
        auto res = mx[m-1][n-1];
        return (res < 0 ? -1 : (res % M) );                            
    }
    
    
public:
    int maxProductPath(vector<vector<int>>& grid) {
        // auto res = min_rec(grid, 0, 0);
        // return (res.second >= 0 ? res.second : -1);
        return max_dp(grid);
    }
};