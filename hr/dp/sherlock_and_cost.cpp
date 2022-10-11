// https://www.hackerrank.com/challenges/sherlock-and-cost/problem
// dynamic-programming, medium

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int solve() {
  int n;
  cin >> n;

  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int h = 0, l = 0;
  for (int i = 1; i < n; i++) {
    int htol = abs(b[i - 1] - 1);
    int ltoh = abs(b[i] - 1);
    int htoh = abs(b[i] - b[i - 1]);

    int l_next = max(l, h + htol);
    int h_next = max(h + htoh, l + ltoh);

    l = l_next;
    h = h_next;
  }

  return max(h, l);
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }
  return 0;
}
