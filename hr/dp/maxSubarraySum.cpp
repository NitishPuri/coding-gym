// https://www.hackerrank.com/challenges/max-array-sum/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.

//! Recursive solution
using vit = vector<int>::iterator;
int maxSum(vit start, vit end) {
  if (start > end)
    return 0;
  if (start == end)
    return *start;
  return max(maxSum(start, end - 2) + *end, maxSum(start, end - 1));
}
int maxSubsetSum_rec(vector<int> arr) {
  return maxSum(arr.begin(), arr.end() - 1);
}

//! Iterative solution with array(linear space)
int maxSubsetSum(vector<int> arr) {
  vector<int> sums(arr.size(), 0);

  sums[0] = arr[0];
  sums[1] = max(sums[0], arr[1]);
  for (int i = 2; i < arr.size(); i++) {
    sums[i] = max(max(sums[i - 1], sums[i - 2] + arr[i]), arr[i]);
  }

  return sums.back();
}

//! Iterative solution without array(constant space)
int maxSubsetSum(vector<int> arr) {
  int s_i_minus_2 = arr[0];
  int s_i_minus_1 = max(s_i_minus_2, arr[1]);
  for (int i = 2; i < arr.size(); i++) {
    int s_i = max(max(s_i_minus_1, s_i_minus_2 + arr[i]), arr[i]);
    s_i_minus_2 = s_i_minus_1;
    s_i_minus_1 = s_i;
  }
  return s_i_minus_1;
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int res = maxSubsetSum(arr);

  cout << res << "\n";

  // cout.close();

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
