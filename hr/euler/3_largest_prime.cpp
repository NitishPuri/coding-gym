// https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem
// project-euler, math, easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long largestPrimeFactor(long long m){
    // keep dividing by 2.
    
    long long mc = m;
    
    long long f = 1;
    if(m%2 == 0){
        f = 2;
        while((m & 1) == 0){
            m = m >> 1;
        }
    }
    
    long long m2 = m;
    
    //cout << "m = " << m << endl;
        
    
    long long i = 3;
    long long l = sqrt(m);
    for(; i <= l && (m > 1); i+=2){
        while(m%i == 0){
            f = i;
            m = m/i;
            //cout << "m = " << m << " f = " << f << endl;
        }
    }    
    
    
    if(f == 1) f = mc;
    else if((f == 2) && (m2 > 2)) f = m2;
    else f = (m > f) ? m : f;
    
    
    return f;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        long long m = 0;        
        cin >> m;
        cout << largestPrimeFactor(m) << endl;
    }
    return 0;
}
