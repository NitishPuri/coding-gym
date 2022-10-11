// https://leetcode.com/problems/longest-ideal-subsequence/
// medium, hash-table, string, dynamic-programming

// acfgbd

#include <string>
#include <unordered_map>

using namespace std;

struct pair_hash {
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &p)  const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

using umap = unordered_map< pair<char, int>, int, pair_hash>;

class Solution {
    // using umap = unordered_map;
    int longest_rec(string s, int k, char last_char, int start, umap& m) {
                
        if(start == s.length()) return 0;
        
        if(m.find({last_char, start}) != m.end()) return m[{last_char, start}];
        
        int res = 0;
        if(last_char == ' ' || abs(s[start] - last_char) <= k) {
            // include s[start] 
            res = 1 + longest_rec(s, k, s[start], start + 1, m);
        }
        
        // not include s[start]            
        res = max(res, longest_rec(s, k, last_char, start + 1, m));
        
        m[{last_char, start}] = res;
                        
        return res;
    }
    
    
public:
    int longestIdealString(string s, int k) {                
        umap m;
        
        return longest_rec(s, k, ' ', 0, m);
    }
};