// https://www.hackerrank.com/challenges/drawing-book/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, p;
    cin >> n >> p;
    
    if( p <= n-p){
        cout << (p/2);
    }
    else{
        n = (n%2) ? n : n+1;
        cout << ( n - p ) / 2;
    }
    
    return 0;
}
