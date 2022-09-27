// https://leetcode.com/problems/snapshot-array

#include <vector>
#include <string>
#include <forward_list>

using namespace std;

class SnapshotArray {
    vector<forward_list<pair<int, int>>> data;
    int next_snap = 0;
public:
    SnapshotArray(int length) {
        data.resize(length, {{0, 0}});
    }
    
    void set(int index, int val) {
        auto& index_head = data[index].front();
        if(index_head.second == next_snap) {
            index_head.first = val;    
        } else {
            data[index].push_front({val, next_snap});
        }        
    }
    
    int snap() {
        next_snap++;
        return next_snap - 1;
    }
    
    int get(int index, int snap_id) {                
        auto itr = data[index].begin();
        while(itr != data[index].end()) {
            if(itr->second <= snap_id) {
                return itr->first;
            }             
            itr++;
        }
        
        return 0;                
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */