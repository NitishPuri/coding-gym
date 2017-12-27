// https://www.hackerrank.com/challenges/day-of-the-programmer/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int y;
    cin >> y;
    if(y < 1917){
        if(y % 4 == 0){
            cout << "12.09." << y;
        }
        else{
            cout << "13.09." << y;            
        }
    }
    else if(y == 1918){
        cout << "26.09.1918";
    }
    else{
        if((y % 400 == 0) || ((y%4 == 0) && (y%100 != 0))){
            cout << "12.09." << y;
        }
        else{
            cout << "13.09." << y;            
        }
    }
    return 0;
}
