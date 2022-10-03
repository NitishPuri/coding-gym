// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
    int countDays(const vector<int>& weights, int cap) {
        int days = 1;
        int c = 0;
        for(auto w : weights) {
            if(c + w > cap) {
                c = 0; days++;
            } 
            c += w;
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_cap = accumulate(weights.begin(), weights.end(), 0);
        int min_cap = *max_element(weights.begin(), weights.end());
        while(min_cap < max_cap) {
            int mid = (min_cap + max_cap) / 2;
            int d = countDays(weights, mid);
            if(d > days) {
                min_cap = mid + 1;
            } else {
                max_cap = mid;
            }
        }
        return min_cap;
    }
};
