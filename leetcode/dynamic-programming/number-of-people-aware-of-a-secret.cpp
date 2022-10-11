// https://leetcode.com/problems/number-of-people-aware-of-a-secret/
// medium, dynamic-programming, queue, simulation

// Day -> #People / Added / Removed / Expr
//  1  ->  1      /  1    /    0    / + 1      = 1
//  2  ->  1      /  0    /    0    / + 0 -0   = 1
//  3  ->  2      /  1    /    0    / + 1 - 0  = 2
//  4  ->  3      / 1+0   /    0    / + 1 - 0  = 3 
//  5  ->  3      / 1 + 0 - 1  = 3
//  6  ->  5     /   1 + 1 - 0 = 5

#include <iostream>
#include <deque>

using namespace std;


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        deque<unsigned int> q;                
        for(int i = 0; i < forget - 1; i++) {
            q.push_back(0);
        }
        unsigned int last_count = 1;
        q.push_back(last_count);
        for(int i = 1; i < n; i++) {        
            auto itr = q.rbegin() + delay-1;
            auto new_people = 0;
            while(itr < q.rbegin() + forget-1) {
                new_people += *itr;
                itr++;
            }
            last_count = last_count + new_people - *itr;
            q.push_back(new_people);
            q.pop_front();
        }
        
        return last_count;
        
    }
};

int main() {
    Solution s;
    cout << s.peopleAwareOfSecret(6, 2, 4);
}