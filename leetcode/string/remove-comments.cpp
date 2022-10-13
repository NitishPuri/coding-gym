// https://leetcode.com/problems/remove-comments
// string, array

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        
        vector<string> res;
        bool in_block_comment = false;
        
        for(int i = 0; i < source.size(); ++i) {
            bool append_to_prev = in_block_comment;
            auto s = source[i];
            
            auto line_start = s.find("//");
            size_t block_start = in_block_comment ? 0 : string::npos;
            size_t block_end = in_block_comment ? s.length() : string::npos;
            while(!s.empty()) {
                if(in_block_comment == false) {
                    block_start = s.find("/*");
                    if(block_start != string::npos) {
                        
                        if(line_start == string::npos || line_start > block_start) {
                            in_block_comment = true;    
                        }                    
                    }                
                }                
                if(in_block_comment == true) {
                    block_end = s.find("*/", append_to_prev ? 0 : block_start + 2);                
                    if(block_end != string::npos) {
                        block_end += 2;
                        in_block_comment = false;                    
                    } else {
                        block_end = s.length();
                    }
                }

                if(block_start != string::npos && block_end != string::npos) {
                    s.erase(block_start, block_end - block_start);                    
                } else {
                    break;
                }                                
                
            }
            
            line_start = s.find("//");
            if(line_start != string::npos) {
                s.erase(line_start, s.length());
                in_block_comment = false;
            }

            
            
            if(!s.empty()) {
                if(append_to_prev) {
                    res.back() += s;
                } else {
                    res.push_back(s);    
                }                
            }
        }
        
        return res;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> source = {
"/*Test program */",
 "int main()",
 "{ ",
 "  // variable declaration ",
 "int a, b, c;",
 "/* This is a test",
 "   multiline  ",
 "   comment for ",
 "   testing */",
 "a = b + c;",
 "}"
    };
    s.removeComments(source);
    return 0;
}
