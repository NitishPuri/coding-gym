// https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
// greedy, easy

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
    
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int mad = arr[1] - arr[0];
    
    for(int i = 1; i < n-1; i++){
        int d = arr[i+1] - arr[i];
        if(mad > d){
            mad = d;
        }
    }
    
    cout << mad;
           
           
    
    return 0;
}
