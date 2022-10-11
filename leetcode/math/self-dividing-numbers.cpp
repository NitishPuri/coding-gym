// https://leetcode.com/problems/self-dividing-numbers/
// easy, math

#include <vector>
using namespace std;

class Solution {
    bool isSelfDividing(int num) {
        if(num == 0) return false;        
        int n = num;
        while(n) {
            auto digit = n % 10;
            if(digit == 0 || (num % digit) > 0) return false;
            n = n / 10;
        }        
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {        
        vector<int> res;        
        for(int i = left; i <= right; i++) {
            if(isSelfDividing(i)) res.push_back(i);
        }        
        return res;        
    }
};