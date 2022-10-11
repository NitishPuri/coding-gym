// https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
// hard, search

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSum function below.
long maximumSum(vector<long> a, long m) {
  long maxSum = 0;

  // partial_sum(a.begin(), a.end(), a.begin(), [m](long long a, long long b) {
  //     return (a % m + b % m) % m;
  // });

  long long curr = 0;
  for (long &a_i : a) {
    long long a_m = a_i % m;
    curr = (a_m + curr) % m;
    a_i = curr;
  }

  set<long> s;
  for (auto itr_i = a.begin(); itr_i < a.end(); ++itr_i) {
    auto upper = s.upper_bound(*itr_i);
    maxSum = max(maxSum, *itr_i);
    if (upper != s.end()) {
      maxSum = max(maxSum, (*itr_i - *upper + m) % m);
    }
    s.insert(*itr_i);
  }

  return maxSum;
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    long m = stol(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<long> a(n);

    for (int i = 0; i < n; i++) {
      long a_item = stol(a_temp[i]);

      a[i] = a_item;
    }

    long result = maximumSum(a, m);

    cout << result << "\n";
  }

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
