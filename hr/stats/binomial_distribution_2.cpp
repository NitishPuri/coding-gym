// https://www.hackerrank.com/challenges/s10-binomial-distribution-2

#include <bits/stdc++.h>

using namespace std;

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

// Poisson coefficient for 'k' successes when average number of successes is 'l'.
// k ==> Number of required success.
// l ==> Average number of success.
double poisson(int k, double l) {
    return (pow(l, k) * exp(-l)) / fact(k);
}

// 
double n_std_dev(double m, double sd, double a){
    a = (a - m) / sd;
    double b = erf(a/sqrt(2.));
    return 0.5*(1+b);
}

#ifndef M_PI
#define M_PI 3.14
#endif
double sqrt_2pi = sqrt(2. * M_PI);
double normal(double m, double sd, double x) {
    x = (x - m) / sd;
    return (1. / (sqrt_2pi * sd) ) * exp(- pow(x, 2) / 2.);
}

double mean(const vector<double>& x) {
    return accumulate(x.begin(), x.end(), 0.0) / x.size();
}

double stddev(const vector<double>& x, double mean) {

    auto squared_diff = [mean](double a, double b){
        return a + pow(b - mean, 2);
    };

    return sqrt(accumulate(x.begin(), x.end(), 0., squared_diff) / x.size());
}

double covariance(const vector<double>& x, const vector<double>& y,
                  double mx, double my) {
    // auto mx = mean(x), my = mean(y);

    double res = 0.0;
    for(int i = 0; i < x.size(); ++i) {
        res += (x[i] - mx) * (y[i] - my);
    }

    return res / x.size();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    double rejects = 0.12;
    int batch_size = 10;

    // No more than 2 rejects = b0 + b1 + b2
    // At least 2 rejects = b2 + b3 + b4 .. b10 = 1 - (b0 + b1)

    double b0 = binomial(batch_size, 0, rejects);
    double b1 = binomial(batch_size, 1, rejects);
    double b2 = binomial(batch_size, 2, rejects);

    double no_more_than_2 = (b0 + b1 + b2);
    double at_least_2 = 1 - (b0 + b1);

    cout << fixed << setprecision(3);
    cout << no_more_than_2 << endl;
    cout << at_least_2;



    return 0;
}
