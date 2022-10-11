// https://leetcode.com/problems/guess-number-higher-or-lower/
// easy, binary-search, interactive

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        
        int lo = 0, hi = n;
        while(true) {
            int mid = lo + (hi - lo) / 2;
            int r = guess(mid);
            if(r == 0) return mid;
            if(r == 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return -1;
        
    }
};