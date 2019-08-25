
// https://www.hackerrank.com/challenges/subset-component
// TODO NP : UNSOLVED

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define BIT(x, i) (x >> i) & 1
#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
//#define PRINTVAR(a) 
#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
//#define PRINTIVEC(v) 


typedef uint64_t lint;

set<lint> getSubset(const vector<lint> & arr, lint sub){
   set<lint> subset;
    for(int i = 0; i < arr.size(); i++){
        if(BIT(sub, i) == 1){
            subset.insert(arr[i]);
        }
    }
    
    return subset;
}

set<lint> reduceSet(set<lint> subset){
    while(true){
        bool reductionFound = false;
        lint k1 = 0, k2 = 0;
        for(auto i : subset){
            for(auto j : subset)
            {
                if(i == j) continue;
                
                if((i & j) != 0) {
                    k1 = i;
                    k2 = j;
                    reductionFound = true;
                    break;
                }
            }
            if(reductionFound) break;
        }
        
        if(reductionFound){
            lint k = (k1 | k2);
            subset.erase(k1);
            subset.erase(k2);
            subset.insert(k);
        }
        else{
            break;
        }
    }
    
    return subset;
}

int num1s(lint n){
    int num = 0;
    //cout << endl << "Start num 1s :: " << n << endl;
    while(n){
      //  PRINTVAR(n);
        if(n & 1) num++;        
        n = (n >> 1);
    }
    //cout << endl << "End num 1s :: " << num << endl;
    
    return num;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    cin >> n;
    
    //num1s(1);
    //return 0;
    
    //PRINTVAR(n);
       
    vector<lint> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];        
    }
    
    //PRINTIVEC(arr);
    
    lint iter = pow(2, n);
    lint answer = 0;
    for(lint i = 0; i < iter; i++){     // iterate over all the subsets.
        set<lint> subset = getSubset(arr, i);
        
        //PRINTVAR(i);
        //PRINTIVEC(subset);
        
        lint components = 64;
                
        subset = reduceSet(subset);

        //PRINTIVEC(subset);
        
        for(auto j : subset){
            if(j == 0) continue;
            
            lint numElem = num1s(j);
            //PRINTVAR(j);
            //PRINTVAR(numElem);
            components -= (numElem - 1);
        }   
                
        //PRINTVAR(components);
        
        answer += components;
    }
    
    
    cout << answer;
    
           
    return 0;
}
