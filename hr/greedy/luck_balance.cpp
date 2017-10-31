// https://www.hackerrank.com/challenges/luck-balance/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    
    int fl = 0;
    vector<int> impc;
    for(int i = 0; i < n; i++){
        int l, t;
        cin >> l >> t;
        if(t == 0){
            fl += l;
        }
        else{
            impc.push_back(l);
        }
    }
    
    sort(impc.begin(), impc.end());
    
    int i = 0;
    for(; i < int(impc.size()) - k; i++){
        fl -= impc[i];
    }
    for(; i < impc.size(); i++){
        fl += impc[i];
    }
    
    cout << fl;
    
    return 0;
}
