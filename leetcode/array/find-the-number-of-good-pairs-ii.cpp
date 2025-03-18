// https://leetcode.com/problems/find-the-number-of-good-pairs-ii/
// medium, array, hash-table

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto n = nums1.size(), m = nums2.size();
    long long res = 0;

    unordered_map<int, long long> m1, m2;
    for (const auto& num : nums1) m1[num]++;
    for (const auto& num : nums2) m2[num]++;

    // cout << "N " << n << endl;
    // cout << "M " << m << endl;
    // cout << "Unique N " << m1.size() << endl;
    // cout << "Unique M " << m2.size() << endl;

    for (auto& num1 : m1) {
      auto count1 = num1.second;
      // cout << "Num1 " << num1.first << " Count " << count1;
      if (num1.first % k == 0) {
        int target = num1.first / k;
        // cout << " Target " << target << endl;
        auto count2 = 0;

        for (int t = 1; t * t <= target; ++t) {
          if (target % t == 0) {
            // cout << "looking for " << t << " " << m2[t] << endl;
            count2 += m2[t];
            if (target / t == t) continue;
            // cout << "looking for " << target / t << " " << m2[target / t] <<
            // endl;
            count2 += m2[target / t];
          }
        }
        // cout << " count2 " << count2;
        res += count1 * count2;
        // cout << " res " << res << endl;
        // for(auto& num2: m2) {
        //     auto count2 = num2.second;
        //     if(num1.first % (num2.first * k) == 0) res += (count1 * count2);
        // }
      } else {
        // cout << endl << " Num1 " << num1.first << "not divisible by k " << k
        // << endl;
      }
    }

    return res;
  }
};