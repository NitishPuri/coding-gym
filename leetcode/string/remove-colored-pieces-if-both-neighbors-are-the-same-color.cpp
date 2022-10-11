// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
// medium, math, string, greedy, game-theory

#include <string>

using namespace std;

class Solution {
        
public:
    bool winnerOfGame(string colors) {        
        int moves_a = 0, moves_b = 0;
        for(int i = 1; i < colors.length()-1; i++) {            
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A') {
                ++moves_a;
            }
            else if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B') {
                ++moves_b;
            }
        }        
        return (moves_a > moves_b);                
    }
};