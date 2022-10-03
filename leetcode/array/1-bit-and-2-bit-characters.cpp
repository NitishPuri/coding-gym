// https://leetcode.com/problems/1-bit-and-2-bit-characters/

#include <vector>

using namespace std;

class Solution {        
public:
    bool isOneBitCharacter(vector<int>& bits) {        
        bool last_one_bit = false;
        for(int i = 0; i < bits.size(); i++) {
            if(bits[i] == 1) {
                i++;
                last_one_bit = false;
            } else {
                last_one_bit = true;                
            }
        }        
        return last_one_bit;        
    }
};