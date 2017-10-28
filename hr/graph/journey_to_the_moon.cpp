// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//#define PRINTVAR(a) cout << #a << " :: " << a << endl; 
#define PRINTVAR(a) 
//#define PRINTIVEC(v) cout << #v << " :: "; for(auto i : v) {cout << i << " , ";} cout << endl;
#define PRINTIVEC(v) 

int findGroup(const vector<int> &groups, int index){
    while(groups[index] != index){
        index = groups[index];
    }
    
    return index;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, p;
    cin >> n >> p;
    
    //PRINTVAR(n);
    //PRINTVAR(p);
    
    vector<int> groups(n);
    vector<int> size(n);
    for(int i = 0; i < n; i++){
        groups[i] = i;
        size[i] = 1;
    }
       
    for(int i = 0; i < p; i++){
        long p1, p2;
        cin >> p1 >> p2;
        
      //  PRINTVAR(p1);
       // PRINTVAR(p2);
        //PRINTIVEC(groups);
        //PRINTIVEC(size);
        
        p1 = findGroup(groups, p1);
        p2 = findGroup(groups, p2);
        if(p1 == p2) continue;

        //PRINTVAR(p1);
        //PRINTVAR(p2);

        if(size[p1] > size[p2]){
            groups[p2] = p1;
            size[p1] = size[p2] + size[p1];
        }
        else{
            groups[p1] = p2;            
            size[p2] = size[p2] + size[p1];
        }

        //PRINTIVEC(groups);
        //PRINTIVEC(size);
    
    }
    
    map<int, long long> groupd;
    for(int i = 0; i < n; i++){
        int g = findGroup(groups, i);
        groupd[g] = size[g];
    }
        
    long long answer = 0;
    vector<int> groupds;
    //cout << "Printing map ::" << endl;
    for(auto m : groupd){
      //  cout << m.first << " :: " << m.second << endl;
        groupds.push_back(m.second);
    }    
    
    PRINTIVEC(groupds);

    
/**    for(int i = 0; i < groupds.size(); i++){
        for(int j = i+1; j < groupds.size(); j++){
            answer += groupds[i]*groupds[j];
            PRINTVAR(answer);
        }
    }    **/
    
    long long sum = 0;
    for(int i = 0; i < groupds.size(); i++){
        answer += sum* groupds[i];
        sum += groupds[i];
    }
    
    cout << answer;
    
    return 0;
}
