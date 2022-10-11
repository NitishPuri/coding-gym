// https://leetcode.com/problems/number-of-days-between-two-dates/
// easy, math, string

#include <iostream>
#include <string>

using namespace std;

class Solution {
    struct Date {
        int year = 0;
        int month = 0;
        int day = 0;
    };
    Date getDate(const string& date_str) {
        Date date;
        int i = 0;
        while(date_str[i] != '-') {
            date.year = date.year*10 + (date_str[i] - '0');
            i++;
        }
        i++;
        while(date_str[i] != '-') {
            date.month = date.month*10 + (date_str[i] - '0');
            i++;
        }
        i++;
        while(i < date_str.length()) {
            date.day = date.day*10 + (date_str[i] - '0');
            i++;
        }        
        return date;        
    }
    
    bool isLeap(int y){
        return y%4==0 && (y%100!=0 || y%400==0);
    }
    
    long countDays(const string& date_str) {
        Date date = getDate(date_str);
        
        int days_count[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        long days = 0;
        for(int y = 1971; y < date.year; y++) {
            days += isLeap(y) ? 366 : 365;
        }
        for(int m = 1; m < date.month; m++) {
            if( m == 2 ) {
                days += isLeap(date.year) ? 29 : 28;
                continue;
            }
            days += days_count[m-1];
        }
        
        days += date.day;
        
        return days;
    }
public:
    int daysBetweenDates(const string& date1, const string& date2) {        
        return abs(countDays(date1) - countDays(date2));        
    }
};

int main() {
    Solution s;
    cout << s.daysBetweenDates("2019-06-29", "019-06-30");
}