// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    
public:
    int largestInteger(int num) {
        
        vector<int> digits;        
        while(num) {
            digits.push_back(num % 10);            
            num = num / 10;
        }

        reverse(digits.begin(), digits.end());
        
        priority_queue<int> odd, even;
        for(auto digit : digits) {
            if(digit % 2 == 1) {
                odd.push(digit);
            } else {
                even.push(digit);
            }
        }
                                
        int res = 0;
        for(auto digit : digits) {
            if(digit % 2 == 1) {
                res = res * 10 + odd.top();
                odd.pop();
            } else {
                res = res * 10 + even.top();
                even.pop();                
            }            
        }
        
        return res;                        
    }
};

int main() {
    Solution s;
    cout << s.largestInteger(1234);
}