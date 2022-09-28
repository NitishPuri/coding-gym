// https://leetcode.com/problems/exam-room/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class ExamRoom {
    list<int> occupied;
    int n;
public:
    ExamRoom(int n) : n(n) {
        
    }
    
    int seat() {
        if(occupied.empty()) {
            occupied.push_back(0);
            return 0;
        }                
        
        int seat = -1;
        auto itr = occupied.begin();
        int max_distance = -1;
        
        // open interval before the first occupied seat;
        if(*itr > 0) {
            seat = 0;
            max_distance = (*itr - 1);
        }
        int prev = *itr;
        itr++;
        
        // closed intervals between occupied seats
        while(itr != occupied.end()) {
            int distance = (*itr - prev) / 2 - 1;
            if(max_distance < distance) {
                max_distance = distance;
                seat = prev + distance + 1;                
            }
            
            prev = *itr;                        
           itr++; 
        }
        
        // open interval after last occupied seat        
        if(prev < n-1) {
            if(max_distance < (n-prev-2)) {
                seat = n-1;
            }
        }

        occupied.insert(upper_bound(occupied.begin(), occupied.end(), seat), seat);
        
        return seat;                
    }
    
    void leave(int p) {
        auto itr = find(occupied.begin(), occupied.end(), p);
        if(itr == occupied.end()) {
            return;
        }
        occupied.erase(itr);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main() {


    // ["ExamRoom","seat","seat","seat","seat","leave","seat"]
    // [[10],[],[],[],[],[4],[]]
    // ExamRoom e(10);
    // cout << e.seat() << endl;
    // cout << e.seat() << endl;
    // cout << e.seat() << endl;
    // cout << e.seat() << endl;
    // e.leave(4);
    // cout << e.seat() << endl;

    // ["ExamRoom","seat","seat","seat","seat","leave","leave","seat"]
    // [[4],[],[],[],[],[1],[3],[]]    
    // [null,0,3,1,2,null,null,1]
    ExamRoom e(4);
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    cout << e.seat() << endl;
    e.leave(1);
    e.leave(3);
    cout << e.seat() << endl;


}