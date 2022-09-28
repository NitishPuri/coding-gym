// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

#include <vector>
#include <queue>

using namespace std;

//  5(101)  2(010)  , k = 1
//  1(001)  6(110)  
//  values
//  101=5  111=7
//  100=4  000=0 , 1th largest = 7


//  5(101)  2(010)  , k = 2
//  1(001)  6(110)  
//  values
//  101=5  111=7
//  100=4  100=4 , 2th largest = 5

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        auto mat = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        
        priority_queue<int> q;        
        q.push(mat[0][0]);
        
        for(int i = 1; i < m; i++) {
            mat[i][0] = (mat[i][0] ^ mat[i-1][0]);
            q.push(mat[i][0]);
        }
        
        for(int i = 1; i < n; i++) {
            mat[0][i] = (mat[0][i] ^ mat[0][i-1]);
            q.push(mat[0][i]);
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                mat[i][j] = (mat[i-1][j-1] ^ mat[i-1][j] ^ mat[i][j-1] ^ mat[i][j]);
                q.push(mat[i][j]);
            }
        }
        
        int res = -1;
        while(k--) {
            res = q.top(); q.pop();
        }
        
        return res;                                        
    }
};