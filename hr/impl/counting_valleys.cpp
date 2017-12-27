//  https://www.hackerrank.com/challenges/counting-valleys/problem

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
    
    char s;
    int h = 0;
    int cv = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        switch(s){
            case 'U' : {
                h++;
                if(h == 0) cv++;
                break;
            }
            case 'D' : {
                h--;
                break;
            }
            default : break;
        }
    }
    
    cout << cv;
    return 0;
}
