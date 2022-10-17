// https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/
// math, string, medium

#include <string>
using namespace std;


class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int login_hh = stoi(loginTime.substr(0, 2));        
        int login_mm = stoi(loginTime.substr(3, 2));
        int logout_hh = stoi(logoutTime.substr(0, 2));        
        int logout_mm = stoi(logoutTime.substr(3, 2));        
                
        if(login_hh < logout_hh || (login_hh == logout_hh && login_mm <= logout_mm)) {
            // 
        } else {
            logout_hh += 24;            
        }
        
        login_mm = ceil(float(login_mm) / 15.0);
        logout_mm = floor(float(logout_mm) / 15.0);                
        return max((logout_hh - login_hh) * 4 + (logout_mm - login_mm), 0);
    }
};