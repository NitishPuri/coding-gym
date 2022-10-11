// https://www.hackerrank.com/challenges/bon-appetit/problem
// implementation, easy

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
    int b = 0;
    int c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(i == k) continue;
        b += c;
    }
    b /= 2;
    int bc;
    cin >> bc;
    if(bc == b){
        cout << "Bon Appetit";
    }
    else{
        cout << (bc - b);
    }
    return 0;
}
