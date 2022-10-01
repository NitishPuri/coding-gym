// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& A) {
        long N = A.size(), ans = LLONG_MAX, sum = accumulate(begin(A), end(A), 0L);
        sort(begin(A), end(A));
        for (int i = 0; i < N; ++i) ans = min(ans, sum - (N - i) * A[i]);
        return ans;        
    }
    long long minimumRemovaln2(vector<int>& beans) {
        long long min_beans = LLONG_MAX;
        for(int i = 0; i < beans.size(); i++) {
            long long curr_beans = 0;
            for(int j = 0; j < beans.size(); j++) {
                curr_beans += (beans[j] >= beans[i] ? beans[j] - beans[i] : beans[j]);
            }
            min_beans = min(min_beans, curr_beans);
        }        
        return min_beans;        
    }
};

int main() {
    Solution s;
    cout << s.minimumRemoval({4,1,6,5});    
}