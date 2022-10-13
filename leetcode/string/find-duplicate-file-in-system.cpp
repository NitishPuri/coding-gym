// https://leetcode.com/problems/find-duplicate-file-in-system/
// array, hash-table, string

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {        
        unordered_map<string, vector<string>> m;
        for(auto& path : paths) {
            auto curr = path.find(' ');
            string dir = path.substr(0, curr);            
            while(curr < path.size()) {
                auto next = path.find('(', curr);
                string name = path.substr(curr + 1, next -  curr -1);
                curr = next;
                next = path.find(')', curr + 1);
                string content = path.substr(curr + 1, next - curr);
                m[content].push_back(dir + "/" + name);
                curr = next + 1;
            }
        }        
        vector<vector<string>> res;
        for(const auto& d : m) {
            if(d.second.size() > 1) {
                res.push_back(d.second);
            }
        }        
        return res;
    }
};