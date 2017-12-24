// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    int s;    
    cin >> s;
    
    int l = s, h = s;
    int cl = 0, ch = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(l < s){
            cl++;
            l = s;
        }
        else if( h > s){
            ch++;
            h = s;
        }
    }
    
    cout << cl << " " << ch;
    return 0;
}
