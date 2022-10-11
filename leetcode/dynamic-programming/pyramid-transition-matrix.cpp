// https://leetcode.com/problems/pyramid-transition-matrix/ 
// medium, bit-manipulation, dynamic-programming, depth-first-search, breadth-first-search

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    map<pair<char, char>, vector<char>> all;
    map<string, bool> memo;
    bool py_rec(const string& bottom) {
        
        if(bottom.size() == 1) return true;
        
        auto itr = memo.find(bottom);
        if(itr != memo.end()) {
            return memo[bottom];
        }
        
        vector<string> res_options(1, "");
        bool have_options = true;
        for(int i = 0; i < bottom.size() - 1; i++) {
            auto itr = all.find({bottom[i], bottom[i+1]}); 
            if(itr == all.end() || itr->second.size() == 0) { 
                have_options = false;
                break;
            }
            auto& char_choices = itr->second;
            int options_len = res_options.size();
            for(int j = 0; j < options_len; j++) {
                res_options[j].push_back(char_choices[0]);
            }                    
            
            auto char_itr = char_choices.begin() + 1;
            while(char_itr != char_choices.end()) {
                for(int j = 0; j < options_len; j++) {
                    string res_copy = res_options[j];
                    res_copy.back() = (*char_itr);
                    res_options.push_back(res_copy);
                }
                char_itr++;
            }
        }
                
        bool res = false;
        if(have_options) {
            for(auto& option: res_options) {
                res = res || py_rec(option);
            }            
        }

        memo[bottom] = res;
        
        return res;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto& allowed_s : allowed) {   // O(a log(a) , a = len(allowed))
            all[{allowed_s[0], allowed_s[1]}].push_back(allowed_s[2]); 
        }
        
        return py_rec(bottom);
    }
};

int main() {
    Solution s;
    // "BCD"
    // ["BCC","CDE","CEA","FFF"]
    // vector<string> allowed{"BCC","CDE","CEA","FFF"};
    // cout << s.pyramidTransition("BCD", allowed); // true

    // vector<string> allowed{"AAB","AAC","BCD","BBE","DEF"};
    // cout << s.pyramidTransition("AAAA", allowed);

// "AFFFFA"
    vector<string> allowed = {"ADA","ADC","ADB","AEA","AEC","AEB","AFA","AFC","AFB","CDA","CDC","CDB","CEA","CEC","CEB","CFA","CFC","CFB","BDA","BDC","BDB","BEA","BEC","BEB","BFA","BFC","BFB","DAA","DAC","DAB","DCA","DCC","DCB","DBA","DBC","DBB","EAA","EAC","EAB","ECA","ECC","ECB","EBA","EBC","EBB","FAA","FAC","FAB","FCA","FCC","FCB","FBA","FBC","FBB","DDA","DDC","DDB","DEA","DEC","DEB","DFA","DFC","DFB","EDA","EDC","EDB","EEA","EEC","EEB","EFA","EFC","EFB","FDA","FDC","FDB","FEA","FEC","FEB","FFA","FFC","FFB","DDD","DDE","DDF","DED","DEE","DEF","DFD","DFE","DFF","EDD","EDE","EDF","EED","EEE","EEF","EFD","EFE","EFF","FDD","FDE","FDF","FED","FEE","FEF","FFD","FFE","FFF"};
    cout << s.pyramidTransition("AFFFFA", allowed);

}