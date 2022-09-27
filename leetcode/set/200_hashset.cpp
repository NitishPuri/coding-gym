#include <iostream>
#include <forward_list>
#include <algorithm>
using namespace std;

class MyHashSet {

    int hash(int key) {
        return key / 1001;
    }

    forward_list<int> buckets[1000];
    
    
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        auto& bucket = buckets[hash(key)];        
        if(find(bucket.begin(), bucket.end(), key) == bucket.end()) {
            bucket.push_front(key);
        }        
    }
    
    void remove(int key) {
        auto& bucket = buckets[hash(key)];        
        bucket.remove(key);        
    }
    
    bool contains(int key) {        
        auto& bucket = buckets[hash(key)];        
        return !(find(bucket.begin(), bucket.end(), key) == bucket.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    MyHashSet s;
    s.add(1);
    s.add(2);
    auto res = s.contains(1);
    res = s.contains(3);
    s.add(2);
    res = s.contains(2);
    s.remove(2);
    s.add(1000000);
    res = s.contains(1000000);
}