// https://www.hackerrank.com/challenges/picking-numbers/problem
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
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
        
    int maxN = 1;
    int curr = 1;
    int start = v[0];
    for(int i = 1; i < n; i++) {
        if(abs(start - v[i]) > 1) {
            maxN = max(maxN, curr);
            start = v[i];
            curr = 1;
        }
        else {
            curr++;
        }
    }
    
    maxN = max(maxN, curr);
    
    cout << maxN;
    
    
    return 0;
}
