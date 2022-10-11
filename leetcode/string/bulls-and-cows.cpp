// https://leetcode.com/problems/bulls-and-cows/
// medium, hash-table, string, counting

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int bulls = 0;
        int cows = 0;
        
        vector<int> m(10, 0);
                
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) { bulls++; continue; }            
            m[secret[i] - '0']++;                                                            
        }
        
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) { continue; }
            if(m[guess[i] - '0'] > 0) {
                cows++;
                m[guess[i] - '0']--;
            }            
        }
                  
        return to_string(bulls) + "A" + to_string(cows) + "B";                        
    }
};