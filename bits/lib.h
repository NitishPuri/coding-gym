// Lib with some intresting functions.
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// Statistics

// n!
int fact(int n) {
    return (n == 0) ? 1 : n * fact(n-1);
}

// nCx ==> choose 'x' samples from 'n' items.
// n ==> Total number of items.
// x ==> Number of samples to be choosen.
// Returns total number of possible combinations.
int comb(int n, int x) {    
    if(n > x) return 0; // error!
    if(n == x || x == 0) return 1;
    return fact(n) / (fact(x) * fact(n-x));
}

// Binomial coefficient for 'x' successes out of 'n' trials
// with 'p' probabiity of success.
// n ==> Total number of trials.
// x ==> Number of successes required.
// p ==> Probability of success on 1 trial.
// Returns probability of 'x' success in 'n' trials.
double binomial(int n, int x, double p) {
    return comb(n, x) * pow(p, x) * pow(1-p, n-x);
}

// Probability of getting atleast 'a' with normal distribution.
// Probability of getting value in range (0, a).
// F(a) = F(0, a) = cumulative probability.
// F(a, b) =  F(b) - F(a).
double n_std_dev(double m, double sd, double a){
    a = (a - m) / sd;
    double b = erf(a/sqrt(2.));
    return 0.5*(1+b);
}


constexpr double sqrt_2pi =sqrt(2. * M_PI);

//! Calculate probability of value x given normal distribution with mean 'm' and standard deviation.
void normal(double m, double sd, double x) {
    x = (x - m) / sd;
    return (1. / (sqrt_2pi * sd) ) * exp(- pow(x) / 2.);
}

// Mean of a dataset.
double mean(const vector<double>& x) {
    return accumulate(x.begin(), x.end(), 0.0) / x.size();
}

// Standard deviation of a dataset.
double stddev(const vector<double>& x, double mean) {

    auto squared_diff = [mean](double a, double b){
        return a + pow(b - mean, 2);
    };

    return sqrt(accumulate(x.begin(), x.end(), 0., squared_diff) / x.size());
}

// Covariance of two datasets.
double covariance(const vector<double>& x, const vector<double>& y,
                  double mx, double my) {
    // auto mx = mean(x), my = mean(y);

    double res = 0.0;
    for(int i = 0; i < x.size(); ++i) {
        res += (x[i] - mx) * (y[i] - my);
    }

    return res / x.size();
}

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
        rank[indices[i]] = i;   // 0 based ranking. i.e. rank 0 is the smallest element.
    }

    return rank;
}






