// https://www.hackerrank.com/challenges/grid-challenge/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solveGrid(){
    int n;
    cin >> n;
    
    vector<vector<char>> grid(n);
    
    for(int i = 0; i < n; i++){
        grid[i].reserve(n);
        for(int j = 0; j < n; j++){
            char ch;
            cin >> ch;
            grid[i].push_back(ch);
        }
    }
    
    sort(grid[0].begin(), grid[0].end());
    
    for(int i = 1; i < n; i++){
        sort(grid[i].begin(), grid[i].end());
        for(int j = 0; j < n; j++){
            if(grid[i-1][j] > grid[i][j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        solveGrid();
    }
    return 0;
}
