// https://leetcode.com/problems/shopping-offers/
// medium, array, dynamic-programming, backtracking, bit-manipulation, memoization, bitmask

#include <map>
#include <vector>

using namespace std;

class Solution {
    map<vector<int>, int> memo;
    int shoppingOffers_rec(const vector<int>& price, const vector<vector<int>>& special, vector<int> needs) {
        
        auto itr = memo.find(needs);
        if(itr != memo.end()) {
            return itr->second;
        }
                
        int best_price = 0;
        int n = price.size();
        
        for(int i = 0; i < n; i++) {
            best_price += (price[i] * needs[i]);
        }
                
        for(int i = 0; i < special.size(); i++) {
            auto needs_copy = needs;
            bool can_accept_offer = true;
            for(int j = 0; j < n ; j++) {
                needs_copy[j] = needs_copy[j] - special[i][j];
                if(needs_copy[j] < 0) {
                    can_accept_offer = false; 
                    break;
                }
            }
            if(can_accept_offer) {
                best_price = min(best_price, shoppingOffers_rec(price, special, needs_copy) + special[i][n]);
            }
        }
        
        memo[needs] = best_price;
        
        return best_price;
    }
    
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shoppingOffers_rec(price, special, needs);
    }
};