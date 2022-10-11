// https://leetcode.com/problems/design-hashmap/
// easy, array, hash-table, linked-list, design, hash-function

#include <iostream>
#include <forward_list>
#include <algorithm>
using namespace std;

class MyHashMap {
    int hash(int key) {
        return key / 1001;
    }
    
    using list = forward_list<pair<int, int>>;

    list buckets[1000];

public:
    MyHashMap() {
        
    }
    
    auto find(list& bucket, int key) {
        return std::find_if(bucket.begin(), bucket.end(), [&](auto& ele){
            return ele.first == key;
        });
    }
    
    void put(int key, int value) {
        auto& bucket = buckets[hash(key)];        
        auto itr = find(bucket, key);
        if(itr == bucket.end()) {
            bucket.push_front({key, value});
        } else {
            itr->second = value;
        }                
    }
    
    int get(int key) {
        auto& bucket = buckets[hash(key)];        
        auto itr = find(bucket, key);
        if(itr == bucket.end()) return -1;
        return itr->second;
    }
    
    void remove(int key) {
        auto& bucket = buckets[hash(key)];        
        bucket.remove_if([&](auto& ele){ return ele.first == key; });                
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
    MyHashMap s;
    s.put(1, 1);
    s.put(2, 2);
    auto res = s.get(1);
    res = s.get(3);
    // s.put(2);
    res = s.get(2);
    s.remove(2);
    s.get(1000000);
    // res = s.contains(1000000);
}