// https://www.hackerrank.com/challenges/richie-rich/problem
// dynamic-programming, string, medium

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
  // const int n = s.length();
  auto s_copy = s;
  const int n_2 = n / 2;
  for (int i = 0; i < n_2; ++i) {
    auto &l = s[i];
    auto &r = s[n - i - 1];
    if (l != r) {
      if (k == 0)
        return "-1";
      if (l > r)
        r = l;
      else
        l = r;
      k--;
    }
  }

  for (int i = 0; i < n_2 && k > 0; ++i) {
    auto &l = s[i];
    auto &r = s[n - i - 1];
    if (l < '9') {
      int cost = 2;
      if (l != s_copy[i] || r != s_copy[n - i - 1]) {
        cost = 1;
      }
      if (k >= cost) {
        l = '9';
        r = '9';
        k -= cost;
      }
    }
  }

  if (k >= 1 && (n & 1)) {
    s[n_2] = '9';
  }

  return s;
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  string s;
  getline(cin, s);

  string result = highestValuePalindrome(s, n, k);

  cout << result << "\n";

  getchar();

  // fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

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
