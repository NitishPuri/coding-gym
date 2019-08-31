// https://www.hackerrank.com/challenges/candies/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {

  vector<long> c(arr.size(), 1);

  c[0] = 1;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] > arr[i - 1]) {
      c[i] = c[i - 1] + 1;
    }
  }

  for (int i = arr.size() - 2; i >= 0; --i) {
    if (arr[i] > arr[i + 1]) {
      c[i] = max(c[i + 1] + 1, c[i]);
    }
  }

  long ret = 0;
  for (auto ci : c)
    ret += ci;

  return ret;
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item;
    cin >> arr_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    arr[i] = arr_item;
  }

  // arr = {4, 6, 4, 5, 6, 2};
  // res = 10

  long result = candies(n, arr);

  cout << result << "\n";

  // fout.close();

  return 0;
}
