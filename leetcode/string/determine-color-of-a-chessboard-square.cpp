// https://leetcode.com/problems/determine-color-of-a-chessboard-square/
// math, string, easy

#include <string>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (((coordinates[0] - 'a' + 1) + (coordinates[1] - '0')) & 1);
    }
};