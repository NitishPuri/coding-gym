// https://leetcode.com/problems/unique-paths/

#include <map>

using namespace std;

class Solution {
    map<pair<int, int>, int> memo;
    int paths_rec(int m, int n) {
        if(m == 1 || n == 1) return 1;        
        auto itr = memo.find({m, n});
        if(itr != memo.end()) return itr->second;
        auto res = paths_rec(m-1, n) + paths_rec(m, n-1);
        memo[{m, n}] = res;
        return res;
    }
public:
    int uniquePaths(int m, int n) {
        return paths_rec(m, n);
    }
};