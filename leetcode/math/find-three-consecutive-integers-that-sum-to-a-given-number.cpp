// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
// medium, math, simulation

#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        auto n3 = num-3;
        if( n3 % 3 ) return {};
        n3 /= 3;
        return {n3 , n3 + 1 , n3 + 2};        
    }
};