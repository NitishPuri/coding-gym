// https://www.hackerrank.com/challenges/insertionsort1/problem

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
    
    // insertion sort
    int v = arr[n-1];
    int i = n-2;
    for(; i >= 0; i--){
        if(arr[i] > v){
            arr[i+1] = arr[i];  
        } 
        else{
            break;
        }
        
        for(int j = 0; j < n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    
    arr[i+1] = v;
    
    for(int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
    
    delete[] arr;
    
    return 0;
}
