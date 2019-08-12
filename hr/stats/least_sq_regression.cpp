#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <functional>
using namespace std;

// Perform least squares linear regression on samples and return a function represnting the line.
function<double (double)> lease_sq_reg(const vector< pair < double , double > >& samples, double& rms) {
    double n = samples.size();

    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xx = 0.0;
    double sum_xy = 0.0;
    for(auto& sample : samples) {
        sum_x += sample.first;
        sum_y += sample.second;
        sum_xx += pow(sample.first, 2);
        sum_xy += (sample.first * sample.second);
    }

    auto m_x = sum_x / n;
    auto m_y = sum_y / n;

    double b = ((n * sum_xy) - (sum_x*sum_y)) / ((n * sum_xx) - pow(sum_x, 2));
    double a = m_y - b * m_x;

    auto reg = [a, b](double x) { return a + b*x; };

    double sse = 0.0;
    for(auto& sample : samples) {
        sse += pow(reg(sample.first) - sample.second, 2);
    }

    rms = sqrt(sse / n);

    return reg;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n_samples = 5;

    vector< pair<double , double> > samples(n_samples);

    // input
    for(auto& sample : samples) cin >> sample.first >> sample.second;

    // regression
    double rms = 0.0;   // Error of least sq regression. Output.
    auto reg = lease_sq_reg(samples, rms);

    // evaluation
    double x = 80.;
    double y = reg(x);

    cout << fixed << setprecision(3);
    cout << y;

    return 0;
}