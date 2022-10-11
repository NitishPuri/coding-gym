// https://leetcode.com/problems/string-compression/
// medium, two-pointers, string

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int ret = 0;        
        char curr = chars[0];
        int curr_len = 1;
        for(int i = 1; i < chars.size(); i++) {
            if(chars[i] == curr) { curr_len++; } 
            else {
                chars[ret++] = curr;
                if(curr_len > 1) {
                    string curr_len_str = to_string(curr_len);
                    for(int j = 0; j < curr_len_str.length(); j++) {
                        chars[ret++] = curr_len_str[j];
                    }                    
                }
                curr = chars[i];
                curr_len = 1;                
            }
        }
        
        chars[ret++] = curr;
        if(curr_len > 1) {
            string curr_len_str = to_string(curr_len);
            for(int j = 0; j < curr_len_str.length(); j++) {
                chars[ret++] = curr_len_str[j];
            }                    
        }          

        return ret;        
    }
};