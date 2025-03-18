// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
// easy, array, hash-table, two-pointers

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                  vector<vector<int>>& nums2) {
    auto n1 = nums1.size(), n2 = nums2.size();
    size_t curr_1 = 0, curr_2 = 0;
    vector<vector<int>> res;
    while (curr_1 < n1 && curr_2 < n2) {
      auto curr_id_1 = nums1[curr_1][0];
      auto curr_id_2 = nums2[curr_2][0];
      auto curr_val_1 = nums1[curr_1][1];
      auto curr_val_2 = nums2[curr_2][1];
      if (curr_id_1 == curr_id_2) {
        res.push_back({curr_id_1, curr_val_1 + curr_val_2});
        ++curr_1;
        ++curr_2;
      } else if (curr_id_1 < curr_id_2) {
        res.push_back({curr_id_1, curr_val_1});
        ++curr_1;
      } else {
        res.push_back({curr_id_2, curr_val_2});
        ++curr_2;
      }
    }

    while (curr_1 < n1) {
      auto curr_id_1 = nums1[curr_1][0];
      auto curr_val_1 = nums1[curr_1][1];
      res.push_back({curr_id_1, curr_val_1});
      ++curr_1;
    }

    while (curr_2 < n2) {
      auto curr_id_2 = nums2[curr_2][0];
      auto curr_val_2 = nums2[curr_2][1];
      res.push_back({curr_id_2, curr_val_2});
      ++curr_2;
    }

    return res;
  }
};