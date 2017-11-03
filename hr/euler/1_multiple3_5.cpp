// https://projecteuler.net/problem=1
// https://www.hackerrank.com/contests/projecteuler/challenges/euler001/copy-from/1303926766

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long sumX(int m, int x){
    long i = (m-1)/x;
    
    return x*i*(i+1)/2;
}

long sum3or5(int m){
    long sum = 0;
    
    sum = sumX(m, 3) + sumX(m, 5) - sumX(m, 15);
    
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        cout << sum3or5(m) << endl;
    }
    return 0;
}
