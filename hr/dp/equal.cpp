// https://www.hackerrank.com/challenges/equal/problem
// medium, dynamic-programming

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int getMin(const vector<int> &c) {
  int min = c[0];
  for (auto i : c) {
    if (min > i)
      min = i;
  }

  return min;
}

void sub(vector<int> &c, int t) {
  for (int i = 0; i < c.size(); i++) {
    c[i] -= t;
  }
}

int reduce(vector<int> &c) {
  int min = c[0];
  int max = c[0];
  for (auto i : c) {
    if (min > i)
      min = i;
    if (max < i)
      max = i;
  }

  for (int i = 0; i < c.size(); i++) {
    c[i] -= min;
  }

  return (max - min);
}

int solveQuery() {
  int n;
  cin >> n;

  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  int minOp = -1;

  int min = getMin(c);
  for (int i = 0; i < 5; i++) {
    int target = min - i;
    // if(target < 0) break;
    // cout << "Solving for target " << target << endl;

    int op = 0;
    for (int j = 0; j < c.size(); j++) {
      int d = c[j] - target;
      op += (d / 5);
      op += (d % 5) / 2;
      op += ((d % 5) % 2);
    }

    // cout << op << endl;
    if (minOp == -1)
      minOp = op;
    if (minOp > op)
      minOp = op;
  }

  return minOp;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solveQuery() << endl;
  }
  return 0;
}
