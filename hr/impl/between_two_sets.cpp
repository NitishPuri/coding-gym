// https://www.hackerrank.com/challenges/kangaroo/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    int t = 0;    
    if(a > b) return gcd(b, a);
    
    while(b > 0){
        t = a;
        a = b;
        b = t%b;
    }    
        
    return a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int lcm(const vector<int>& a){
    if(a.size() == 0) return 1;
    
    int l = a[0];
    for(int i = 1; i < a.size(); i++){
        l = lcm(l, a[i]);
    }
    
    return l;
}

int gcd(const vector<int>& a){
    if(a.size() == 0) return 1;
    
    int g = a[0];
    for(int i = 1; i < a.size(); i++){
        g = gcd(g, a[i]);
    }   
    return g;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
        
    // lcm of a
    int la = lcm(a);
        
    // gcd of b
    int gb = gcd(b);
    
    int f = 1;
    int c = 0;
    while(la <= gb){
        if(gb%la == 0) c++;
        la = (la/f)*(f+1);
        f++;
    }
    
    cout << c;
    
    return 0;
}
