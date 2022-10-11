// https://www.hackerrank.com/challenges/insertionsort2/problem
// sorting, easy

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
    
    int *arr = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 1; i < n; i++){
        int v = arr[i];
        int j = i-1;
        for(; j >= 0; j--){
            if(arr[j] > v){
                arr[j+1] = arr[j];
            }
            else{ break; }
        }
        
        // insert
        arr[j+1] = v;
        
        for(int k = 0; k < n; k++){
            cout << arr[k] << " ";
        }
        cout << endl;    
    }
    
    delete[] arr;
    
    return 0;
}
