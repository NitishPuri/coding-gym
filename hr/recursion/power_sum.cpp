// https://www.hackerrank.com/challenges/the-power-sum/problem
// recursion, medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countSums(int n, int p, int s){    
    
    if(n == 0){
        return 1;
    } 
    else if(n < pow(s, p)){
        return 0;
    }
    else {
        return countSums(n - pow(s, p), p, s+1) + countSums(n, p, s+1);
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, p;
    cin >> n >> p;
    
    cout << countSums(n, p, 1);
    
    
    return 0;
}
