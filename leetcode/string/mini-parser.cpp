// https://leetcode.com/problems/mini-parser/
// medium, string

#include <string>
#include <vector>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
    bool isdigit(char ch) {
        return '0' <= ch && ch <= '9';
    }
    NestedInteger des_rec(string& s, int& curr) {  
        if(curr > s.length()) return {};
        if(s[curr] == '[') {            
            NestedInteger res;
            ++curr;
            while(s[curr] != ']') {
                if(s[curr] == ',') ++curr;
                res.add(des_rec(s, curr));                
            }
            ++curr;
            
            return res;
        }
        
        if(s[curr] == ']') {
            return NestedInteger();
        }
                
        int num = 0;
        int mul = 1;
        if(s[curr] == '-') {
            ++curr;
            mul = -1;
        }
        while(isdigit(s[curr])) {
            num = num * 10 + (s[curr] - '0');
            ++curr;
        }
        
        return NestedInteger(num * mul);                
    }
    
public:
    NestedInteger deserialize(string s) {
        int curr = 0;
        return des_rec(s, curr);                        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.deserialize("-3");
    return 0;
}
