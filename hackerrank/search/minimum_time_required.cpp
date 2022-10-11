// https://www.hackerrank.com/challenges/minimum-time-required/problem
// medium, search

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
  auto getNumItems = [&](long num_days) {
    long production = 0;
    for (auto machine : machines) {
      production += floor(num_days / machine);
    }
    return production;
  };

  auto min_item = *min_element(machines.begin(), machines.end());
  long min = min_item * goal / machines.size(), max = min_item * goal;

  cout << "Min : " << min << "  ,  "
       << "Max : " << max << endl;

  while (min != max) {
    long mid = (min + max) / 2;
    long production = getNumItems(mid);
    if (production >= goal)
      max = mid;
    else
      min = mid + 1;

    cout << "Min : " << min << "  ,  "
         << "Max : " << max << "  ,  ";
    cout << "Mid : " << mid << "  ,  "
         << "Production : " << production << endl;
  }

  return min;
}

int main() {
  // ofstream fout(getenv("OUTPUT_PATH"));

  string nGoal_temp;
  getline(cin, nGoal_temp);

  vector<string> nGoal = split_string(nGoal_temp);

  int n = stoi(nGoal[0]);

  long goal = stol(nGoal[1]);

  string machines_temp_temp;
  getline(cin, machines_temp_temp);

  vector<string> machines_temp = split_string(machines_temp_temp);

  vector<long> machines(n);

  for (int i = 0; i < n; i++) {
    long machines_item = stol(machines_temp[i]);

    machines[i] = machines_item;
  }

  long ans = minTime(machines, goal);

  cout << ans << "\n";

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
