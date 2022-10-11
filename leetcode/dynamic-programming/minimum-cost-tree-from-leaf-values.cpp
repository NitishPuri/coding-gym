// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

// copied from https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/340033/C%2B%2B-with-comments

//  6  2  4

// T(start, end) = sum = min [  (T(start, i).sum + T(i, end).sum + T(start, i).max*T(i, end).max )
//                     for i in range(start + 1, end)    ]
//                  max = max() 

// T(0, 1) = sum = min{  T(0, 0).sum + T(1, 1).sum + T(0,0).max*T(1,1).max  }
// T(0, 1) = min{  0 + 6 + 0*0  } =  6

// i       0      1       2       3
//    v    .      6       2       4
// 0  .   (0,0)   6
// 1  6          6,6
// 2  2                   2,2
// 3  4                            4,4

#include <vector>

using namespace std;

class Solution {
public:
    int memo[41][41];
    int maxi[41][41];
    
    int dp(int left,int right){
        if(left==right)return 0; //leaf node
        if(memo[left][right]!=-1)return memo[left][right];
        
        int ans = 1<<30;
        
        for(int i=left;i<right;i++)
            ans= min(ans, maxi[left][i] * maxi[i+1][right] + dp(left,i) + dp(i+1,right) );
        
        memo[left][right]=ans;
        return ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<arr.size();i++){
            maxi[i][i] = arr[i];
            for(int j=i+1;j<arr.size();j++)
                maxi[i][j] = max(maxi[i][j-1], arr[j]);
        }
        
        return dp(0,arr.size()-1);
    }
};