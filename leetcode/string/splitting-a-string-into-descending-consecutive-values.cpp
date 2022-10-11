// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
// medium, string, backtracking

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    
    public:
    bool helper(string a, string b){
        if(stoull(a)-stoull(b)==1) return true;
        for(int i=1; i<b.length(); i++){
            string x=b.substr(0, i);
            string y=b.substr(i, b.length()-i);
            if(stoull(b.substr(0, i)) != stoull(a)-1) continue;
            if(helper(x, y)) return true;
        }
        return false;
    }
    
    bool splitString(string s) {
        for(int i=1; i<s.length(); i++){
            string a=s.substr(0, i);
            string b=s.substr(i, s.length()-i);
            if(helper(a, b))
                return true;
        }
        return false;
    }
};
