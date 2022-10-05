// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

// 1 1 1 0 0 1 --> 1: 3, 0: 0
// 0 1 1

#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[] = {0, 0}, i = 0;;
        for(auto stud : students) count[stud]++;
        for(; i < sandwiches.size() && count[sandwiches[i]] > 0; ++i) {
            count[sandwiches[i]]--;            
        }
        return students.size() - i;        
    }
};