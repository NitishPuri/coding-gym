// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
// hash-table, string, backtracking, medium

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    
    int rec(const string& s, int start, unordered_set<string>& seen) {                    
        int ans = 0;
        for(int i = start; i < s.length(); ++i) {
            string split = s.substr(start, i + 1 - start);            
            if(seen.find(split) == seen.end()) {
                seen.insert(split);
                ans = max(ans, 1 + rec(s, i + 1, seen));
                seen.erase(split);
            }
        }        
        return ans;    
    }
public:
    int maxUniqueSplit(string s) {        
        unordered_set<string> seen;
        return rec(s, 0, seen);                
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.maxUniqueSplit("ababccc");
    return 0;
}
