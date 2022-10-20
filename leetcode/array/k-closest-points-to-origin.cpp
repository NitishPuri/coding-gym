// https://leetcode.com/problems/k-closest-points-to-origin/
// array, math, divide-and-conquer, geometry, sorting, priority-queue, quickselect, medium

#include <vector>
#include <algorithm>
using namespace std;



double distance(const vector<int>& p) {
    return (p[0]*p[0]  + p[1]*p[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // [1] : Sort entire array
        // sort(begin(points), end(points), [](auto& a, auto& b){
        //     return distance(a) < distance(b);
        // });
        // points.resize(k);
        // return points;
        
        
        // [2] : partition using quick select         
        nth_element(begin(points), begin(points) + k, end(points), [](auto& a, auto& b){
            return distance(a) < distance(b);
        });
        points.resize(k);
        return points;

// [3] : Use Priority queue
//         int n = points.size();
//         vector<float> d(n);
//         for(int i = 0; i < n; ++i) {
//             d[i] = distance(points[i]);
//         }
//         auto points_compare = [&](int l, int r) -> bool {
//             // return distance(points[l]) < distance(points[r]);
//             return d[l] < d[r];
//         };
                        
//         priority_queue<int, vector<int>, decltype(points_compare)> pq(points_compare);
        
//         for(int i = 0; i < points.size(); ++i) {
//             pq.push(i);
//             if(pq.size() > k) pq.pop();
//         }
        
//         vector<vector<int>> res(k);
//         for(int i = k-1; i >= 0; --i) {
//             res[i] = points[pq.top()];
//             pq.pop();
//         }
        
//         return res;
    }
};