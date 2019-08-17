// Lib with some intresting functions.
#include <algorithm>
#include <functional>
#include <map>
#include <math.h>
#include <numeric>
#include <vector>

// Statistics

// n!
int fact(int n) { return (n == 0) ? 1 : n * fact(n - 1); }

// nCx ==> choose 'x' samples from 'n' items.
// n ==> Total number of items.
// x ==> Number of samples to be choosen.
// Returns total number of possible combinations.
int comb(int n, int x) {
  if (n > x)
    return 0; // error!
  if (n == x || x == 0)
    return 1;
  return fact(n) / (fact(x) * fact(n - x));
}

// Binomial coefficient for 'x' successes out of 'n' trials
// with 'p' probabiity of success.
// n ==> Total number of trials.
// x ==> Number of successes required.
// p ==> Probability of success on 1 trial.
// Returns probability of 'x' success in 'n' trials.
double binomial(int n, int x, double p) {
  return comb(n, x) * pow(p, x) * pow(1 - p, n - x);
}

// Probability of getting atleast 'a' with normal distribution.
// Probability of getting value in range (0, a).
// F(a) = F(0, a) = cumulative probability.
// F(a, b) =  F(b) - F(a).
double n_std_dev(double m, double sd, double a) {
  a = (a - m) / sd;
  double b = erf(a / sqrt(2.));
  return 0.5 * (1 + b);
}

constexpr double M_PI = 22 / 7;
const static double sqrt_2pi = sqrt(2. * M_PI);

//! Calculate probability of value x given normal distribution with mean 'm' and
//! standard deviation.
double normal(double m, double sd, double x) {
  x = (x - m) / sd;
  return (1. / (sqrt_2pi * sd)) * exp(-pow(x, 2) / 2.);
}

// Mean of a dataset.
double mean(const std::vector<double> &x) {
  return std::accumulate(x.begin(), x.end(), 0.0) / x.size();
}

// Standard deviation of a dataset.
double stddev(const std::vector<double> &x, double mean) {
  auto squared_diff = [mean](double a, double b) {
    return a + pow(b - mean, 2);
  };

  return sqrt(std::accumulate(x.begin(), x.end(), 0., squared_diff) / x.size());
}

// Covariance of two datasets.
double covariance(const std::vector<double> &x, const std::vector<double> &y,
                  double mx, double my) {
  // auto mx = mean(x), my = mean(y);

  double res = 0.0;
  for (int i = 0; i < x.size(); ++i) {
    res += (x[i] - mx) * (y[i] - my);
  }

  return res / x.size();
}

// Rankify a given vector. Using STL.
template <typename T> std::vector<size_t> rankify(const std::vector<T> &x) {
  std::vector<size_t> rank(x.size(), 0);

  // Create Index array
  std::vector<size_t> indices(x.size());
  std::iota(indices.begin(), indices.end(), 0);

  // sort index array based on values from original array.
  std::sort(indices.begin(), indices.end(),
            [&x](size_t i1, size_t i2) { return x[i1] < x[i2]; });

  for (size_t i = 0; i < x.size(); ++i) {
    // 0 based ranking. i.e. rank 0 is the smallest element.
    rank[indices[i]] = i;
  }

  return rank;
}

// Pearson coefficient.
double pearson(const std::vector<double> &x, const std::vector<double> &y) {
  auto mx = mean(x), my = mean(y);
  auto n = x.size();

  double cov = 0.0, sd_x = 0.0, sd_y = 0.0;
  for (int i = 0; i < n; ++i) {
    cov += (x[i] - mx) * (y[i] - my);
    sd_x += pow(x[i] - mx, 2);
    sd_y += pow(y[i] - my, 2);
  }

  cov /= n;
  sd_x = sqrt(sd_x / n);
  sd_y = sqrt(sd_y / n);

  return cov / (sd_x * sd_y);
}

// Spearman coefficient in case of unique values in datasets.
double spearman(const std::vector<double> &x, const std::vector<double> &y) {
  auto n = x.size();

  auto rank_x = rankify(x);
  auto rank_y = rankify(y);

  double sum_d = 0.0;
  for (size_t i = 0; i < n; ++i) {
    sum_d += pow(rank_x[i] - rank_y[i], 2);
  }

  auto res = 1. - (6 * sum_d) / (n * (n * n - 1));
  return res;
}

// Perform least squares linear regression on samples and return a function
// represnting the line.
std::function<double(double)>
lease_sq_reg(const std::vector<std::pair<double, double>> &samples,
             double &rms) {
  double n = samples.size();

  double sum_x = 0.0;
  double sum_y = 0.0;
  double sum_xx = 0.0;
  double sum_xy = 0.0;
  for (auto &sample : samples) {
    sum_x += sample.first;
    sum_y += sample.second;
    sum_xx += pow(sample.first, 2);
    sum_xy += (sample.first * sample.second);
  }

  auto m_x = sum_x / n;
  auto m_y = sum_y / n;

  double b = ((n * sum_xy) - (sum_x * sum_y)) / ((n * sum_xx) - pow(sum_x, 2));
  double a = m_y - b * m_x;

  auto reg = [a, b](double x) { return a + b * x; };

  double sse = 0.0;
  for (auto &sample : samples) {
    sse += pow(reg(sample.first) - sample.second, 2);
  }

  rms = sqrt(sse / n);

  return reg;
}

// Example code for file input/output scaffolding.
void setup_input() {
    ifstream fin("input.txt");
    if(!fin.is_open()) {
        cout << "Bad input." << endl;
        return 0;
    }

    ifstream fres("results.txt");
    if(!fres.is_open()) {
        cout << "Bad input." << endl;
        return 0;
    }

    int T;
    fin >> T;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// Bidirectional map.
template <typename A, typename B> struct bi_map {
  bi_map(const std::map<A, B> &map)
      : _a_to_b(map), _b_to_a([&map]() {
          std::map<B, A> rev;
          for (const auto &ab : map) {
            rev[ab.second] = ab.first;
          }
          return rev;
        }()) {}

  B a_to_b(A a) { return _a_to_b.at(a); }
  A b_to_a(B b) { return _b_to_a.at(b); }

private:
  const std::map<A, B> _a_to_b;
  const std::map<B, A> _b_to_a;
};
