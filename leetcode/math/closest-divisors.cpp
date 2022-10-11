// https://leetcode.com/problems/closest-divisors/
// medium, math

#include <vector>

using namespace std;

class Solution {
    struct Res {
        int a = 0;
        int b = 0;
    };
    Res closest(int num) {
        Res r{1, num};
        for(int i = 2; i <= sqrt(num); i++) {
            if(num % i == 0) {
                if(abs(i - num/i) < abs(r.a - r.b)) {
                    r = {i, num/i};
                }
            }
        }
        return r;
    }
    
public:
    vector<int> closestDivisors(int num) {                
        auto res1 = closest(num+1);
        auto res2 = closest(num+2);
        if(abs(res1.a - res1.b) < abs(res2.a - res2.b)) {
            return {res1.a, res1.b};
        }        
        return {res2.a, res2.b};        
    }
};