// https://www.hackerrank.com/contests/projecteuler/challenges/euler002/copy-from/1303926920
// project-euler, math, easy
// https://projecteuler.net/problem=2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Sum of all the even fibonacci numbers less than the given input.
void processQuery(){
    long long n;
    cin >> n;
    
    long long a1 = 1;
    long long a2 = 1;
    long long a3 = a1+a2;
    
    long long sum = 0;
    
    while(a3 < n){
        if(!(a3 & 1)) sum += a3;
        a1 = a2;
        a2 = a3;
        a3 = a1+a2;
    }
    
    cout << sum << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        processQuery();
    }
    return 0;
}
