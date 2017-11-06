// https://www.hackerrank.com/challenges/recursive-digit-sum/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long super_digit(long long s){
    if(s < 10) return s;
    
    long long sup = 0;
    while(s){
        int r = (s%10);
        sup += r;
        s /= 10;
    }
    
    return  super_digit(sup);    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string n;
    long k;
    cin >> n >> k;
    
    long long sumn = 0;
    for(int i = 0; i < n.size(); i++){
        sumn += (n[i] - '0');
    }
    sumn *= k;
    
    cout << super_digit(sumn);
    
    return 0;
}
