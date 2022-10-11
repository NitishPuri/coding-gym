// https://www.hackerrank.com/challenges/marcs-cakewalk/problem
// easy, greedy

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
    
    vector<int> cake(n);
    
    for(int i = 0; i < n; i++){
        cin >> cake[i];
    }
    
    sort(cake.begin(), cake.end());
    
    long miles = 0;
    long fact = 1;
    for(int i = n-1; i >=0; i--){
        miles += (fact*cake[i]);
        fact *= 2;
    }
    
    
    cout << miles;
    
    return 0;
}
