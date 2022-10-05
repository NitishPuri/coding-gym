// https://leetcode.com/problems/goat-latin/

#include <string>
#include <iostream>

using namespace std;

class Solution {
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'A' || ch =='e' || ch =='E' || ch == 'i' || ch == 'I' 
                || ch =='o' || ch == 'O' || ch == 'u' || ch == 'U');
    }
    bool isSpace(char ch) {
        return ch == ' ';
    }
public:
    string toGoatLatin(string sentence) {
        string res;
        int i = 0, word_index = 1;
        while(i < sentence.length()) {            
            int j = i;
            while(j < sentence.length() && sentence[j] != ' ') ++j;
            if( isVowel(sentence[i]) ) {
                res += sentence.substr(i, j - i) + "ma";
            } else {
                res += sentence.substr(i+1, j - i-1) + sentence[i] + "ma";
            }
            for(int k = 0; k < word_index; ++k) res += 'a';
            res+= ' ';
            i = j + 1;
            ++word_index;
        }
        res.resize(res.length() - 1);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.toGoatLatin("I speak Goat Latin");
    return 0;
}
