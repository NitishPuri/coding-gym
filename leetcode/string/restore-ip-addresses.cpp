// https://leetcode.com/problems/restore-ip-addresses
// string, backtracking

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        int n = s.length();
        
        for(int i = 0; i < 3; ++i) {
            if(i < n - 10) continue;
            if(s[0] == '0' && i > 0) break;
            
            int a = stoi(s.substr(0, i+1));
            
            if(a > 255) break;
            
            for(int j = i+1; j < i + 4; ++j) {
                if(j < n - 7) continue;;
                if(s[i+1] == '0' && j > i + 1) break;
                
                int b = stoi(s.substr(i + 1, j - i));
                if(b > 255) break;
                
                for(int k = j + 1; k < j + 4; ++k) {
                    if(k < n - 4) continue;;
                    if(s[j+1] == '0' && k > j + 1) break;
                    
                    int c = stoi(s.substr(j + 1, k - j));
                    if(c > 255) break;
                    
                    for(int l = k + 1; l < k + 4; ++l) {
                        if(l < n - 1) continue;
                        if(s[k+1] == '0' && l > k + 1) break;
                        
                        int d = stoi(s.substr(k + 1, l - k));
                        if(d > 255) break;
                        
                        string r = to_string(a) + '.' + to_string(b) + '.' + to_string(c) + '.' + to_string(d);
                        res.push_back(r);
                    }
                }
                    
                
            }
            

        }
        
        return res;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.restoreIpAddresses("25525511135");
    return 0;
}
