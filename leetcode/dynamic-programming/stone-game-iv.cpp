// https://leetcode.com/problems/stone-game-iv
// hard, dynamic-programming, math

// 1 -> t (1-> 0)
// 2 -> f (2-> 1-> 0)
// 3 -> t (3 -> 2-> 1-> 0)
// 4 -> t (4-> 0)
// 5 -> f (5-> 1-> 0 -> f) || (5-> 4-> 0 -> f)
// 6 -> t  (6 -> 2 -> t) || (6 -> 5 -> t)
// 7 -> f  (7-> 3 -> f)
// 8 -> t  (8->4 ->0 f) || (8 -> 7 -> t)
// 9 -> t
// 10 -> f  (10 -> 1 -> 0 -> f) || (10 -> 6 -> f)
// 11 -> f || !(11->2->f) || .. -> t
// 12 -> f || !(12->3->t) || !(12->8->t) || !(12->11->t) -> f
// 13 -> f || !(13->4->t) || !(13->9->t) || !(13->12->f) -> t
// 14 -> f || !(14->5->f) -> t
// 15 -> f || !(15->6->t) || !(15->11->t) || !(15->14->t) -> f
// 16 -> f || !(16->7->f) -> t
// 17 -> f || !(17->8->y) || !(17->13->t) || !(17->16->t) -> f

#include <vector>
using namespace std;


class Solution {
    bool isSq(int n) {
        float s = sqrt(n);
        return s == float(floor(s));
    }
public:
    bool winnerSquareGame(int n) {
        
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        
        vector<int> squares;
        squares.push_back(1);        
                
        for(int i = 2; i < n+1; ++i) {                        
            if(isSq(i)) {
                dp[i] = true;
                squares.push_back(i);
            } else {
                for(int j = squares.size() - 1; j >= 0; --j) {
                    dp[i] = dp[i] || !dp[i - squares[j]];
                    if(dp[i]) break;
                }
            }                                    
        }
        
        return dp[n];                        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.winnerSquareGame(17);
    return 0;
}
