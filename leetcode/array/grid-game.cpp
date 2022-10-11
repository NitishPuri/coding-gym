// https://leetcode.com/problems/grid-game/
// medium, matrix, prefix-sum

#include <vector>

using namespace std;

// 20,3,20,17,2,12,15,17,4,15
// 20,10,13,14,15,5,2,3,14,3

// 0   1   2   3   4   5   6   7   8   9 
// 20  23  43  60  62  74  89  106 110 125
// 20  30  43  57  72  77  79  82  96  99 

// 119 102 112 116 104 101 111 128 127 128
// i  -> r2_score
// 0  ->  105 
// 1  ->  max(20, 125 - 23 = 102) = 102
// 2  ->  max(30, 125 - 43 = 82) = 82
// 3  ->  max(43, 125 - 60 = 65) = 65
// 4  ->  max(57, 125 - 62 = 63) = 63
// 5  ->  max(72, 125 - 74 = 51) = 72
// 6  ->  max(77, 125 - 89 = 36) = 77
// 7  ->  max(79, 125 - 106 = 19) = 79
// 8  ->  max(82, 125 - 110 - 15) = 82
// 9  ->  96

// 2  5  4 -> 2  7  11
// 1  5  1 -> 1  6  7

// 9 , max(1, 11 - 7 = 4) = 4 , 6

// 9 13 12
// 0 0 4  
// 1 0 0

// 

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        // prefix sum
        int n = grid[0].size();
        vector<vector<long long>> sums(2, vector<long long>(n, 0));
        sums[0][0] = grid[0][0];
        sums[1][0] = grid[1][0];        
        for(int i = 1; i < n; ++i) {
            sums[0][i] = sums[0][i-1] + grid[0][i];
            sums[1][i] = sums[1][i-1] + grid[1][i];
        }

        long long r2_score = sums[0][n-1] - sums[0][0];        
        for(int i = 1; i < n; ++i) {
            r2_score = min(r2_score, max( sums[1][i-1], sums[0][n-1] - sums[0][i])  );
        }
                
        return r2_score;                        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // [[20,3,20,17,2,12,15,17,4,15],[20,10,13,14,15,5,2,3,14,3]] = 63
    // [[2,5,4],[1,5,1]] = 4
    // [[3,3,1],[8,5,2]] = 4
    // [[1,3,1,15],[1,3,3,1]] = 7
    // vector<vector<int>> grid {
    //     {20,3,20,17,2,12,15,17,4,15},
    //     {20,10,13,14,15,5,2,3,14,3}
    // };
    vector<vector<int>> grid {
        {2, 5, 4}, {1, 5, 1}
    };
    s.gridGame(grid);
    return 0;
}
