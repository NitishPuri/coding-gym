// https://leetcode.com/problems/unique-binary-search-trees/
// medium, math, dynamic-programming, tree, binary-search-tree

#include <vector>

using namespace std;

//  T(i) = SUM( T( 1, j, i) , for j in range(1, i))
// T(i, j, r) = T(j-i) * T(r - j);
//  T(i) = SUM(  T(j-1) * T(i-j) , for j in range(1, i))

// T0 = 1
// T1 = SUM (  T(1, 1, 1) ) = SUM(T0*T0 ) = 1
// T2 = SUM(  T(1, 1, 2) + T(1, 2, 2) ) = SUM( T(0)*T(1) + T(1) * T(0)) = 2

class Solution {
public:
    int numTrees(int n) {        
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }        
        return dp[n];                                
    }
};