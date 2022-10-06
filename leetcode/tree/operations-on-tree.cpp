// https://leetcode.com/problems/operations-on-tree/

#include <vector>
#include <map>

using namespace std;

class LockingTree {
    vector<int> parent;
    vector<vector<int>> children;
    map<int, int> locks;
    
    bool is_locked(int num) {
        return (locks.find(num) != locks.end());
    }
    bool has_locked_descendent(int num) {
        auto& children_of_num = children[num];         
        auto n = children_of_num.size();
        for(int i = 0; i < n; ++i) {
            auto& child = children_of_num[i];
            if(is_locked(child)) return true;            
            if(has_locked_descendent(child)) return true;
        }        
        return false;
    }
    
    bool has_locked_ancestor(int num) {        
        if(num == -1) return false;
        auto& parent_of_num = parent[num];
        if(is_locked(parent_of_num)) return true;        
        return has_locked_ancestor(parent_of_num);
    }
    
    void unlock_all_descendents(int num) {
        auto& children_of_num = children[num];
        auto n = children_of_num.size();
        for(int i = 0; i < n; ++i) {            
            auto& child = children_of_num[i];
            auto itr = locks.find(child);
            if(itr != locks.end()) {
                locks.erase(itr);
            }
            unlock_all_descendents(child);        
        }                
    }
    
    
public:
    LockingTree(vector<int>& p) {
        parent = p;
        
        // build children
        children.resize(parent.size());
        for(int i = 1; i < parent.size(); ++i) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(locks.find(num) != locks.end()) return false;
        locks[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        auto itr = locks.find(num);
        if(itr == locks.end()) return false;
        if(itr->second != user) return false;
        locks.erase(itr);
        return true;
    }
    
    bool upgrade(int num, int user) {
        // node is unlocked
        if(locks.find(num) != locks.end()) return false;
        
        // has at least one locked descendent
        if(!has_locked_descendent(num)) return false;
        
        // does not have any locked ancestors
        if(has_locked_ancestor(num)) return false;
        
        // perform upgrade
        {
            // lock node
            lock(num, user);    
            
            // unlock all descendents
            unlock_all_descendents(num);
        }
        
        return true;                
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main(int argc, char const *argv[])
{
    vector<int> parents{-1, 0, 0, 1, 1, 2, 2};
    LockingTree l(parents);
    l.lock(2, 2);
    l.unlock(2, 3);
    l.unlock(2, 2);
    l.lock(4, 5);
    l.upgrade(0, 1);
    l.lock(0, 1);
    return 0;
}
