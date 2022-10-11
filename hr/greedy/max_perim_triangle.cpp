// https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
// greedy, easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
#define PRINTVAR(a) cout << #a << " :: " << a << endl; 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> e(n);
    
    for(int i = 0; i < n; i++){
        cin >> e[i];
    }
    
    sort(e.begin(), e.end());
    
    //PRINTIVEC(e);
    
    int p = 0;
    int a, b, c;
    bool succcess = false;
    
    for(int i = n-1; i > 1; i--){
        a = e[i];
        b = e[i-1];
        c = e[i-2];
        //PRINTVAR(a);
        //PRINTVAR(b);
        //PRINTVAR(c);
        
        
        if( (b+c) <= a){
            continue;       // degenerate
        }
        else{
            p = (a+b+c);
            succcess = true;
            break;
        }        
    }
    
    //PRINTVAR(p);
    if(succcess)
        cout << c << ' ' << b << ' ' << a;
    else
        cout << -1;
    
    
    return 0;
}
