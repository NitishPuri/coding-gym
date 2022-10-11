// https://leetcode.com/problems/four-divisors/
// medium, array, math

#include <vector>

using namespace std;

class Solution {
    
    int countDivisors(int num) {
        int count = 2;
        int sum = 1 + num;
        for(int i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                count++;
                sum += i;
            }
            if(count > 4) {
                return 0;
            }            
        }
        
        return (count == 4 ? sum : 0);
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res += countDivisors(nums[i]);
        }
        return res;
        
    }
};