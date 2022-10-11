// https://leetcode.com/problems/defuse-the-bomb/
// easy, array

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0) return vector<int>(code.size(), 0);                
        int n = code.size();
        vector<int> res(n, 0);
        int k_a = abs(k);
        int k_s = k / abs(k);
        int cum_sum = 0;
        for(int i = 1; i <= k_a; i++) {
            cum_sum += code[ (k_s*i + n) % n ];
        }
        res[0] = cum_sum;
        
        for(int i = 1; i < n; i++) {
            if(k > 0) {
                cum_sum = cum_sum - code[i] + code[ (i + k + n) % n];    
            } else {
                cum_sum = cum_sum - code[ (i + k-1 + n) % n ] + code[ (i - 1 + n) % n];    
            }
            
            res[i] = cum_sum;
        }
        
        return res;                        
    }
};

int main() {
    Solution s;
    s.decrypt({5,7,1,4}, 3);

    // [2,4,9,3] , -2
    s.decrypt({2,4,9,3}, -2);
}