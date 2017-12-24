// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem

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
    vector<int> a(n);
    for(auto& i : a){
        cin >> i;
    }
    
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i+1; j < a.size(); j++){
            if((a[i] + a[j]) % k == 0) count++;
        }
    }
    
    cout << count;
    
    return 0;
}
