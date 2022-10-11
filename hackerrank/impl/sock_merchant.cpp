//  https://www.hackerrank.com/challenges/sock-merchant/problem
// implementation, easy

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
    int c[101] = {0};
    int ci;
    int count = 0;
    for(int i = 0; i < n ; i++){
        cin >> ci;
        if(c[ci] == 1){
            count++;
            c[ci] = 0;
        }
        else{
            c[ci] = 1;
        }
    }
    
    cout << count;
    
    return 0;
}
