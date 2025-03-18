// https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/
// medium, array, greedy, sorting

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
    auto n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return abs(nums[0] - k);

    sort(nums.begin(), nums.end());  // n*log(n)
    auto med = nums[n / 2];

    long long res = 0;

    if (med == k) return 0;

    if (med < k) {
      for (size_t i = n - 1; i >= n / 2; i--) {
        if (nums[i] < k) res += (k - nums[i]);
      }
      return res;
    }

    // else med > k
    for (size_t i = 0; i <= n / 2; i++) {
      if (nums[i] > k) res += (nums[i] - k);
    }
    return res;
  }
};