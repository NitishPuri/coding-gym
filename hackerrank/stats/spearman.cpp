// https://www.hackerrank.com/challenges/s10-spearman-rank-correlation-coefficient/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;

// Rankify a given vector. Using STL.
template<typename T>
vector<size_t> rankify(const vector<T>& x) {

    vector<size_t> rank(x.size(), 0);

    // Create Index array
    vector<size_t> indices(x.size());
    iota(indices.begin(), indices.end(), 0);

    // sort index array based on values from original array.
    sort(indices.begin(), indices.end(), [&x](size_t i1, size_t i2){
        return x[i1] < x[i2];
    });

    for(size_t i = 0; i < x.size(); ++i) {
        rank[indices[i]] = i + 1;
    }

    return rank;
}

double spearman(const vector<double>& x, const vector<double>& y) {
    auto n = x.size();
    
    auto rank_x = rankify(x);
    auto rank_y = rankify(y);

    double sum_d = 0.0;
    for(size_t i = 0; i < n; ++i) {
        sum_d += pow(int(rank_x[i]) - int(rank_y[i]), 2);
    }

    auto res = 1. - (6 * sum_d) / (n * (n*n - 1));
    return res;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n;

    vector<double> x(n, 0), y(n, 0);
    for(auto& xi : x) cin >> xi;
    for(auto& yi : y) cin >> yi;

    cout << fixed << setprecision(3);
    cout << spearman(x, y);

    return 0;
}
