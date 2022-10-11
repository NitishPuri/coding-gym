// https://www.hackerrank.com/challenges/hackerland-radio-transmitters
// search, medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
#define PRINTVAR(a)  

//#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
#define PRINTIVEC(v) 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
        
    for(int i = 0; i < n; i++){                        
        cin >> x[i];        
    }
        
    sort(x.begin(), x.end());
    
    PRINTIVEC(x);
        
    int i = 0;
    int c = 0;
    while(i < n){        
        int j = 1;
        PRINTVAR(i);
        for(; j < k+1, (i+j) < n; j++){
            if(x[i+j] > (x[i]+k)) break;
        }
        j--;
        PRINTVAR(i+j);
        int xj = x[i+j];
        int l = 1;
        for(; l < k+1, (i+j+l) < n; l++){
            if(x[i+j+l] > (xj+k)) break;
        }
        i = i+j+l;
        c++;
    }
        
    int r = 2*k + 1;
    
    cout << c;
    
    return 0;
}
