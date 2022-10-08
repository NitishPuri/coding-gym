// https://leetcode.com/problems/minimum-sum-of-squared-difference/

//     1  2  3  4
//     2 10 20 19
// d=  1  8  17  15

// 4 4 4 3 = 57
// 3 3 4 3 = 43

// 1 4 10 12
// 5 8 6 9
// 4 4 4 3  
// m { {4, 1} , {3, 1}}
// pq {4, 3}

// k = 2
// pop 4, c = 3 * 1, push 4, m[4] = 1

// 11 12 13 14 15
// 13 16 16 12 14
// k = 9
// d = 2  4  3  2  1
// m { { 2, 0}, {4, 0}, {3, 0}, {1, 3}, {0, 2}}
// pq { 1}

// pop 4, c = 1, k = 8, 
// pop 3, c = 2, k = 6, 
// pop 2, c = 4, k = 2
// pop 1, c = 5, 

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;



class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums, vector<int>& nums2, int k1, int k2) {
        
        int n = nums.size();
        priority_queue<int> pq;
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i) {
            int d = abs(nums[i] - nums2[i]);
            if(d) m[d]++;
        }
        
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            pq.push(itr->first);
        }
        
        long long k = k1+ k2;
        while(!pq.empty() && k > 0) {
            int r = pq.top(); pq.pop();
            int c = m[r] * (r -  (pq.empty() ? 0 : pq.top()));
            if( k < c ) {
                while(k >= m[r]) {                    
                    m[r-1] += m[r]; pq.push(r-1);
                    m[r] = 0;                    
                    k -= m[r-1];
                    --r;
                }
                pq.push(r);
                m[r] -= k;
                m[r-1] += k; pq.push(r-1);
                k = 0;
            } else {
                k -= c;
                m[pq.top()] += m[r];
                m[r] = 0;                                    
            }                        
        }
        
        long long res = 0;
        while(!pq.empty()) {
            long long r = pq.top();
            res += r * r * m[r];
            m[r] = 0;
            pq.pop();
        }
        
        return res;                                                
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> n1 { 11,12,13,14,15 };
    vector<int> n2 {13,16,16,12,14};
    s.minSumSquareDiff(n1, n2, 3, 6);

    return 0;
}
