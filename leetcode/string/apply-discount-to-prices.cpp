// https://leetcode.com/problems/apply-discount-to-prices/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool isDigit(char ch) {
        return (ch >= '0') && (ch <= '9');        
    }
    string toString(double val) {        
        if(val == 0) return "0.00";
        val = val * 100;
        string res = to_string(long long(val));
        if(res.length() == 1) {
            res = "0.0" + res;
        } else if(res.length() == 2) {
            res = "0." + res;
        } else {
            res = res.substr(0, res.length() - 2) + "." + res.substr(res.length() - 2, 2);
        }
        
        return res;
        // return to_string(int(val)) + "." + to_string(int( (val - int(val))*100 ));
    }
public:
    string discountPrices(string sentence, float discount) {
        string res;
        
        
        vector<string> words;
        int word_start = 0;
        for(int i = 0; i < sentence.length(); i++) {
            if(sentence[i] == ' ') {
                words.push_back(sentence.substr(word_start, i - word_start));
                word_start = i+1;
            }
        }
        words.push_back(sentence.substr(word_start, sentence.length() - word_start));
        
        for(auto word : words) {
            if(word[0] != '$') {
                res += word + " ";
                continue;
            }
            
            bool is_valid_num = (word.length() > 1);
            for(int i = 1; i < word.length(); i++) {
                if(!isDigit(word[i])) {                    
                    is_valid_num = false;
                    break;
                }
            }
            if(is_valid_num == false) {
                res += word + " ";
                continue;
            }
            word[0] = '0';
            
            double num = stof(word);
            double d = 100 - discount;
            num = num * d;
            num = num / 100.0;
            // num = (num * float(100.0 - discount)) / 100.0;            
            res += string("$") + toString(num) + " ";                        
        }
        
        res.resize(res.length()-1);
        
        return res;
                        
    }
};

int main() {
    Solution s;
    // cout << s.discountPrices("there are $1 $2 and 5$ candies in the shop", 50) << endl;

    // str ="1 2 $3 4 $5 $6 7 8$ $9 $10$";
    // discount = 100;
    // cout << s.discountPrices(str, discount);

    // str = "$7383692 5q $5870426";
    // discount = 64;
    // cout << s.discountPrices(str, discount);

    // cout << s.discountPrices("$76111 ab $6 $", 48);

    // cout << s.discountPrices("706hzu76jjh7yufr5x9ot60v149k5 $7651913186 pw2o $6", 28);

    cout << s.discountPrices("$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999", 99);
}