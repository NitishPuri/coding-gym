// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array
// array, string, divide-and-conquer, sorting, priority-queue, quickselect, hard

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), [](string& s1, string& s2){
            if(s1.length() != s2.length()) {
                return (s1.length() > s2.length());
            }            
            return s1 > s2;                                    
        });
        return nums[k-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> v {"0", "0", "0", "0", "10"};
    cout << s.kthLargestNumber(v, 3);
    return 0;
}
