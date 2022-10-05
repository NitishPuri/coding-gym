// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int max_words = INT_MIN;
        for(auto& sentence : sentences) {
            
            int word_count = 1;
            for(int i = 0; i < sentence.length(); ++i) {
                if(sentence[i] == ' ') ++word_count;
            }
            
            max_words = max(max_words, word_count);                                    
        }
        return max_words;
    }
};