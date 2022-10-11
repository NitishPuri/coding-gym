// https://leetcode.com/problems/jump-game-v/
// hard, dynamic-programming, sorting

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxJumps(const vector<int>& arr, int d) { // O(n) + O(n*log(n)) + O(n * d) + O(n)
        
        int n = arr.size();
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);            // O(n)
        stable_sort(indices.begin(), indices.end(), [&arr](auto i1, auto i2){ return arr[i1] < arr[i2]; });  // O(n*log(n))
        
        
        vector<int> res(n, 1);
        
        for(int k = 0; k < n; k++) {            // O(n)
            int i = indices[k];
            // jump left
            for(int j = i-1; j >= max(0, i-d); j--) {  // O(d)
                if(arr[i] <= arr[j]) break;
                res[i] = max(1 + res[j], res[i]);                    
            }
            // jump right            
            for(int j = i+1; j <= min(n-1, i+d); j++) {
                if(arr[i] <= arr[j]) break;
                res[i] = max(1 + res[j], res[i]);                    
            }                    
        }
        
        return *max_element(res.begin(), res.end());   // O(n);                                                     
    }
};

int main() {
    Solution s;
    cout << s.maxJumps({6,4,14,6,8,13,9,7,10,6,12}, 2);
}