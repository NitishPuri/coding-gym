// https://www.hackerrank.com/challenges/migratory-birds/problem

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
    int t[5] = {0};
    
    int ti;
    for(int i = 0; i < n; i++){
        cin >> ti;
        t[ti-1]++;
    }
    
    int mt = t[0], m = 1;
    for(int i = 1; i < 5; i++){
        if(mt < t[i]){
            mt = t[i];
            m = i+1;
        }
    }
    
    cout << m;
    
    return 0;
}
