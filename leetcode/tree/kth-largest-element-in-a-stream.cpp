// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <queue>

using namespace std;

// 3, 4 5 8 2
// -4, -5, -8, 

// -5, -5, -8


class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for(int i = 0; i < min(k, n); ++i) {
            pq.push(-nums[i]);            
        }
        
        for(int i = k; i < nums.size(); ++i) {
            add(nums[i]);
        }
        
    }
    
    int add(int val) {
        if(pq.size() < k) {
            pq.push(-val);
            return -pq.top();
        }
        
        if(-val >= pq.top()) {
            return -pq.top();
        }
        
        pq.pop();
        pq.push(-val);
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */