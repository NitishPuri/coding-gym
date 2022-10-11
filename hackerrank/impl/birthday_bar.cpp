//  https://www.hackerrank.com/challenges/the-birthday-bar/problem
// implementation, easy

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
    
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    
    int d, m;
    cin >> d >> m;
    
    int sum = 0;
    int count = 0;
    for(int i = 0; i < m; i++){
        sum += c[i];
    }
    if(sum == d) count++;
    
    for(int i = 0; i < n-m; i++){
        sum -= c[i];
        sum += c[i+m];
        if(sum == d) count++;
    }
    
    cout << count;
    return 0;
}
