// https://leetcode.com/problems/html-entity-parser/
// medium, hash-table, string


#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
        
    char map_symbol(const string& symbol) {
        static map<string, char> m {
            {"&quot;", '\"'},  
            {"&apos;", '\''},  
            {"&amp;", '&'},  
            {"&gt;", '>'},  
            {"&lt;", '<'},  
            {"&frasl;", '/'},  
        };
        
        auto itr = m.find(symbol);
        if(itr == m.end()) {
            return ' ';
        }
        return itr->second;
    }
public:
    string entityParser(string text) {
        
        string res;
        int word_start = -1;
        for(int i = 0; i < text.length(); i++) {
            if(word_start != -1) {
                if(text[i] == ';') {
                    auto symbol = text.substr(word_start, i - word_start+1);
                    auto ch = map_symbol(symbol);
                    if(ch != ' ') {
                        res += ch;
                    } else {
                        res += symbol;
                    }
                    word_start = -1;
                } else if(text[i] == '&') {
                    res += text.substr(word_start, i-word_start);
                    word_start = i;
                }
                continue;
            }
            if(text[i] == '&') {
                word_start = i;
                continue;
            }
            
            res += text[i];
                        
        }
        
        if(word_start != -1) {
            res += text.substr(word_start, text.length()-word_start);
        }
        
        return res;
    }
};
int main() {
    Solution s;

    cout << s.entityParser("&amp; is an HTML entity but &ambassador; is not.");

}