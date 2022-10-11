// https://www.hackerrank.com/challenges/greedy-florist/problem
// greedy, medium, array

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PRINTVAR(a) cout << #a << " :: " << a << endl; 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n , k;
    cin >> n >> k;
    
    vector<int> cost(n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    
    //int f = ceil(float(n)/float(k));
    
    sort(cost.begin(), cost.end());
    
    long tc = 0;
    int m = 1;
    int f = 0;
    for(int i = n-1; i >= 0; i-- ){
        if(f == k){
            m += 1;
            f = 0;
            //PRINTVAR(m);
        }
        //PRINTVAR(cost[i]*m);
        tc += cost[i]*m;
        f += 1;
    }
    
    cout << tc;
    
    
    return 0;
}
