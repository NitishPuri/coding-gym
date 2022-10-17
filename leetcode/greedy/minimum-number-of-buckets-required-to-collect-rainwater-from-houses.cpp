// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
// greedy, medium, string, dynamic-programming

//  H . . H
//  0 1 1 0

// . H . H .
// 0 0 1 0 0

#include <string>
using namespace std;

class Solution {    
public:
    int minimumBuckets(string street) {
        int n = street.length();        
        int res = 0;        
        for(int i = 0; i < n; ++i) {
            
            if(street[i] == 'H') {
                // check if it has a bucket on the left
                if(i > 0 && street[i-1] == 'B') continue;                                
                
                if(i < n -1 && street[i+1] == '.') {  // try yo place bucket on the right
                    street[i+1] = 'B';
                    ++res;
                } else if(i > 0 && street[i-1] == '.') {        // try to place on left                    
                    street[i-1] = 'B';
                    ++res;
                } else {        // cannot place bucket on either side of this house.
                    return -1;
                }
            }            
        }        
        return res;        
    }
};