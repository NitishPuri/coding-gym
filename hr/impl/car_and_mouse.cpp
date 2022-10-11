// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
// implementation, easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    
    int a, b, c;
    for(int i = 0; i < q; i++){
        cin >> a >> b >> c;
        a = abs(a-c);
        b = abs(b-c);
        if(a < b)       cout << "Cat A";
        else if(a > b)  cout << "Cat B";
        else            cout << "Mouse C";
        cout << endl;
    }
    return 0;
}
