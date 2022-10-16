// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers
// array, hash-table, matrix

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        unordered_set<int> s;
        for(int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        
        auto column_s = s, row_s = s;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                column_s.erase(matrix[i][j]);
                row_s.erase(matrix[j][i]);
            }
            if(!column_s.empty() || !row_s.empty()) return false;
            column_s = s;
            row_s = s;
        }
        
        return true;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> m {
        {1,2,2,4,5,6,6},
        {2,2,4,5,6,6,1},
        {2,4,5,6,6,1,2},
        {4,5,6,6,1,2,2},
        {5,6,6,1,2,2,4},
        {6,6,1,2,2,4,5},
        {6,1,2,2,4,5,6}        
    };
    s.checkValid(m);
    return 0;
}
