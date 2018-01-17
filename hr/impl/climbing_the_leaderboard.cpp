// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
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
    vector<int> scores(n);
    for(int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int i = 0; i < m; i++) {
        cin >> alice[i];
    }
    
    vector<int> ranks(m);
    int curr = 1;
    int rIndex = m-1;
    int i = 0;
    while(rIndex >= 0) {
        if(alice[rIndex] >= scores[i]) {            
            ranks[rIndex--] = curr;         // Decrement in alices games
        }
        else{
            i++; if(i >= n) break;
            if(scores[i] < scores[i-1]) {
                curr++;                     // Increment rank.
            }            
        }
    }
    while(rIndex >= 0) {
        ranks[rIndex--] = curr+1;
    }
        
    for(int i = 0; i < m; i++) {
        cout << ranks[i] << endl;
    }
    
    
    return 0;
}
