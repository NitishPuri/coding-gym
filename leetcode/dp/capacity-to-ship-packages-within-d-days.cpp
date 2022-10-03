// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// 1 2 3  4  5  6  7  8  9 10  <- weights 
// 1 3 6 10 15 21 28 36 45 55 <- prefix sum

// day = 1 , min_cap = 55
// day = 2 , 1 3 6 10 15 21 28 = 28, 36 45 55 = 55 - 28 = 27 -> 28
// day = 3 ,  21 , 36 - 21 = 15 , 55 - 36 = 19 -> 21
// day = 4 ,  55/4 = 13 , 15 , 28 - 15 = 13 , 45 - 28 = 17 , 55 - 45 = 10 -> 17
// day = 5 , 55/5 = 11 , [ 10 , 21 - 10 = 11 , 36 - 21 = 15, 55 - 36 = 19 ->19  


// T5(0, 9, 5) = min {  max(T(0, i, .) , T(i, 10, 4))  for i in range(0, 9) }

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
    map<pair<int, int>, int> memo;
    int ship_rec(const vector<int>& sums, int start, int end, int days) {
        if(days == 1) { 
            return sums[end - 1] - (start == 0 ? 0 : sums[start - 1]); 
        }

        auto itr = memo.find({start, days});
        if(itr != memo.end()) return itr->second;

        int ans = INT_MAX;
        int sums_start = (start == 0 ? 0 : sums[start - 1]);
        for(int i = start; i < end; i++) {
            ans = min(ans, max(sums[i] - sums_start, ship_rec(sums, i+1, end, days-1)));
        }

        memo[{start, days}] = ans;
        
        return ans;        
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        vector<int> sums(weights.size(), 0);
        for(int i = 0; i < weights.size(); i++) {
            sums[i] = (i == 0 ? 0 : sums[i-1]) + weights[i];
        }
        return ship_rec(sums, 0, weights.size(), days);
    }
};

int main() {
    Solution s;
    vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << s.shipWithinDays(weights, 5);
}