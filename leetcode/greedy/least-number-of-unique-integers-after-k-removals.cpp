// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

// 4 3 1 1 3 3 2
// 4 : 1 , 3 : 3, 1: 2, 2 : 1
// 1 : 2, 2: 1, 3: 1
// 

#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(const vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for(int a : arr) { count[a]++; }
        
        map<int, int> freq;
        auto itr_c = count.begin();
        while(itr_c != count.end()) { 
            freq[itr_c->second]++; itr_c++;
        }
        
        auto unique_count = 0;
        auto itr_f = freq.begin();
        while(itr_f != freq.end()) {
            auto total_elem = itr_f->first * itr_f->second;
            if(k == 0) {
                unique_count += itr_f->second;
            }
            else if(k < (total_elem)) {                
                unique_count += ceil(float(total_elem - k) / float(itr_f->first));
                k = 0;
            } else {
                k -= total_elem;
            }
            itr_f++;
        }
        
        return unique_count;
        
        
        
    }
};

int main() {
    Solution s;
    s.findLeastNumOfUniqueInts({2,4,1,8,3,5,1,3}, 3);
}