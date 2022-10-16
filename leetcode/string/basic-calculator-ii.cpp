// https://leetcode.com/problems/basic-calculator-ii/
// 3 + 3 * 2 + 5 * 6
// (3 + (3 * 2) + (5 *6)

#include <stack>
#include <string>

using namespace std;


class Solution {
    bool isdigit(char ch) {
        return '0' <= ch && ch <= '9';
    }
    bool isSpace(char ch) {
        return ch == ' ';
    }
public:
    int calculate(string s) {        
        stack<int> st;        
        int n = s.length();
        int current_num = 0;
        char current_op = '+', curr_char = s[0];
        for(int i = 0; i < n; ++i) {
            curr_char = s[i];
            if(isdigit(curr_char)) {
                current_num = current_num * 10 + (curr_char - '0');
            }
            if(!isdigit(curr_char) && !isSpace(curr_char) || i == n - 1) {
                if(current_op == '+') {
                    st.push(current_num);
                } else if(current_op == '-') {
                    st.push(-current_num);
                } else if(current_op == '*') {
                    auto t = st.top() * current_num; st.pop();
                    st.push(t);
                } else if(current_op == '/') {
                    auto t = st.top() / current_num; st.pop();
                    st.push(t);
                }
                current_num = 0;
                current_op = curr_char;
            }                                    
        }        
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }        
        return res;                
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.calculate("42");
    return 0;
}
