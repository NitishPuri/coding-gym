// https://leetcode.com/problems/image-smoother/
// easy, matrix, array

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        auto res = img;
        int m = img.size();
        int n = img[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int c = 0, s = 0;
                for(int k = i-1; k <=i+1; k++) {
                    for(int l = j-1; l <=j+1; l++) {
                        if(0 <= k && k < m && 0 <= l && l < n) {
                            c++; s+= img[k][l];
                        }
                    }
                }                                
                res[i][j] = s / c;
            }
        }
        return res;
    }
};