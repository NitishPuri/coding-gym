// https://leetcode.com/problems/destroying-asteroids
// array, greedy, sorting

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        unsigned long long m = mass;
        sort(asteroids.begin(), asteroids.end());        
        for(auto ast : asteroids) {
            if(m < ast) return false;
            m += ast;
        }        
        return true;
    }
};