// https://leetcode.com/problems/my-calendar-iii/
// hard, binary-search, design, segment-tree, ordered-set

// (10, 20) -> 1
// (50, 60) -> 1
// {10, 40} -> 2
// (5, 15) -> 3
// (5, 10) -> 3
// (25, 55) -> 3

// {5, 2} {10,1} {15, -1} (25, 1)  {20, -1} , {40, -1}, {50, 1}, {55, -1}, {60, -1}

#include <map>

using namespace std;

class MyCalendarThree {
    map<int, int> events;
    
public:
    MyCalendarThree() {
        
    }
    
    void set(int key, int val) {
        auto itr = events.find(key);
        if(itr == events.end()) {
            events[key] = val;
        } else {
            events[key] += val;
        }
    }
    
    int book(int start, int end) {
        set(start, 1);
        set(end, -1);
        int curr = 0;
        int res = 0;
        for(auto itr : events) {
            curr += itr.second;
            res = max(res, curr);
        }
        return res;        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */