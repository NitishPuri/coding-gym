// https://leetcode.com/problems/unique-morse-code-words
// aray, hash-table, string

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                              ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                              "...","-","..-","...-",".--","-..-","-.--","--.."};        
        unordered_set<string> u;        
        for(const auto& word : words) {
            string tf;
            for(int i = 0; i < word.length(); ++i) {
                tf += codes[word[i] - 'a'];
            }
            u.insert(tf);
        }
        
        return u.size();
    }
};