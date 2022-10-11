// https://www.hackerrank.com/challenges/making-candies/problem
// search, hard

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumPasses function below.
using ull = unsigned long long;
ull minimumPasses(ull m, ull w, ull p, ull n) {
  ull curr = 0;
  ull days = 0;

  // long min_days = 0;
  // long max_days = ceill(n / (m * w));

  // while (min_days != max_days)
  // {
  //     long mid = (min_days + max_days) / 2;
  //     // Calculate how much can be produced in 'mid' days
  //     long min_production = m * w * mid;
  // }

  while (curr < n) {
    if (curr >= p) {
      ull rem = n - curr;
      if (rem > m * w) {
        ull mw = curr / p;

        if (m >= w + mw) {
          w += mw;
        } else if (w >= m + mw) {
          m += mw;
        } else {
          ull total = m + w + mw;
          m = total / 2;
          w = total - m;
        }

        curr = (curr % p);
      }
    }

    // Skip ahead to buy more resources.
    ull skip = (p > curr) ? ceill(long double(p - curr) / (m * w)) : 1;

    if (skip == 0) {
      skip = 1;
    }

    if (curr + (skip * m * w) > n) {
      ull rem = n - curr;
      if (rem < m * w) {
        skip = 1;
      }
    }
    curr += skip * m * w;

    days += skip;
  }

  return days;
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));

  string mwpn_temp;
  getline(cin, mwpn_temp);

  vector<string> mwpn = split_string(mwpn_temp);

  long m = stol(mwpn[0]);

  long w = stol(mwpn[1]);

  unsigned long long p = stoull(mwpn[2]);

  unsigned long long n = stoull(mwpn[3]);

  ull result = minimumPasses(m, w, p, n);

  cout << result << "\n";

  // fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y && x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
