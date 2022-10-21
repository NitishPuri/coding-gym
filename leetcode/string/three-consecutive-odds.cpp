// https://leetcode.com/problems/three-consecutive-odds/
// easy, array

#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(auto a : arr) {
            if(a & 1) ++count;
            else count = 0;
            if(count == 3) return true;
        }
        return false;
    }
};