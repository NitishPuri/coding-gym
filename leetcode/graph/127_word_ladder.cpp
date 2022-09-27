// https://leetcode.com/problems/word-ladder/

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
    
    int dist(const string& s1, const string& s2) {
        int ret = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) ret++;
        }
        return ret;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) return 0;        
                
        queue<string> q;        
        q.push(endWord);
        words.erase(endWord);
        int res = 0;
        
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            if(dist(curr, beginWord) == 1) return res;
            vector<string> to_remove;
            for(auto itr = words.begin(); itr != words.end(); itr++) {
                if(dist(curr, *itr) == 1) {
                    q.push(*itr);
                    to_remove.push_back(*itr);
                }
            }
            for(const auto& word : to_remove) {
                words.erase(word);
            }
                        
            res++;            
        }
                                                
        return res;                
    }
};