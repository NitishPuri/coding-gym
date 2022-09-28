// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/submissions/

#include <vector>
#include <string>

using namespace std;

// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
// Output: true
// Explanation:
// word1 represents string "ab" + "c" -> "abc"
// word2 represents string "a" + "bc" -> "abc"
// The strings are the same, so return true.

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int w1 = 0, w2 = 0, c1 = 0, c2 = 0;
        while(true) {
            if(word1[w1][c1] != word2[w2][c2]) return false;
            
            c1++; 
            if(c1 == word1[w1].length()) { w1++; c1 = 0; }            
                
            c2++;
            if(c2 == word2[w2].length()) { w2++; c2 = 0; }
            
            if(w1 == word1.size() && w2 == word2.size()) return true;
            if(w1 == word1.size() || w2 == word2.size()) return false;            
        }
        
        return true;
        
    }
};