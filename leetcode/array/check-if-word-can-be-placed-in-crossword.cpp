// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, const string word) {
        
        const int m = board.size(), n = board[0].size(), p = word.size();
        string rev = word;
        reverse(rev.begin(), rev.end());

        // t = 0 -> match row , 1 -> match column
        auto match = [&board, &p](const string& word, int i, const int n, const int t){
            int j = 0, k = 0;
            while(j < n) {
                auto ch = (t == 0 ? board[i][j] : board[j][i]);
                if(ch == '#') k = 0;
                else if (k != -1) {
                    if(ch == ' ' || ch == word[k]) ++k;
                    else k = -1;                    
                    if( k == p) {
                        if(j == n-1 || (t == 0 ? (board[i][j+1] == '#') : (board[j+1][i] == '#')) ) return true;
                        k = -1;
                    }
                }
                ++j;
            }
            return false;
        };

        
        for(int i = 0; i < m; ++i) {
            if( match(word, i, n, 0) ) return true;
            if( match(rev, i, n, 0) ) return true;
        }
        
        for(int j = 0; j < n; ++j) {
            if( match(word, j, m, 1) ) return true;
            if( match(rev, j, m, 1) ) return true;
        }
        
        return false;                        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<vector<char>> board {
    //     {'#', ' ', '#'},
    //     {' ', ' ', '#'},
    //     {'#', 'c', ' '}
    // };
    // s.placeWordInCrossword(board, "abc");

    vector<vector<char>> board2 {
        {' ', '#', 'a'},
        {' ', '#', 'c'},
        {' ', '#', 'a'}
    };
    s.placeWordInCrossword(board2, "ac");

    return 0;
}
