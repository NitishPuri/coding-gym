// https://www.hackerrank.com/challenges/kangaroo/problem
// easy, implementation

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    int dx = x2 - x1;
    int dv = v1 - v2;
    
    if(dv == 0){
        if(dx == 0){
            cout << "YES";            
        }
        else{
            cout << "NO";
        }
    }
    else{
        int t = dx/dv;    
        if(t > 0 && (dx%dv == 0)){
            cout << "YES";
        }
        else{
            cout << "NO";
        }        
    }
    return 0;
}
