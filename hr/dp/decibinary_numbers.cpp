// https://www.hackerrank.com/challenges/decibinary-numbers/problem
// dynamic-programming, hard, unsolved

// TODO :: UNSOLVED

#define CATCH_CONFIG_MAIN
#include <bits/stdc++.h>

#include <bits/catch.hpp>

using namespace std;

long to_decimal(const std::string &str) {
  long dec = 0;
  for (int i = 0; i < str.size(); ++i) {
    dec += (str[i] - '0') * pow(2, (str.size() - 1 - i));
  }
  return dec;
}

long to_decimal(long d) {
  return d;
  // return to_decimal(to_string(d));
}

// map<long, long> count {
//     {0, 1} , {1, 1} //,  {2, 2}, {3, 2}
// };

long decibinaryNumbers(long x) {

  if (x <= 2)
    return x - 1;

  long curr = 1;
  constexpr int CUMSUM = -1;

  vector<long> cumsum;
  map<long, map<int, int>> sol;
  sol[0] = {{1, 1}};
  cumsum.push_back(1);
  sol[1] = {{1, 1}};
  cumsum.push_back(2);

  int n = 2;
  while (true) {
    int place = 1;
    int value = 1;
    int rem = n;
    while (true) {
      // int value = pow(2, power);
      for (int digit = 1; digit <= 9; ++digit) {
        if (value * digit > rem) {
          break;
        } else {
          rem = rem - (value * digit);
          sol[n][place] += sol[rem][place - 1];
        }
      }
      place += 1;
      value *= 2;
      if (value > n) {
        // cumsum.push_back()
        break;
      }
    }
    n++;
  }

  // precompute
  // while(x > sol[curr][CUMSUM]) {
  //     curr++;

  //     sol[curr] = vector<int>(11, 0);
  //     auto& curr_sol = sol[curr];
  //     curr_sol[CUMSUM] = sol[curr-1][CUMSUM];

  //     int i = (curr % 2 == 0) ? 8 : 9;

  //     for( ;i >= 0; i-=2) {
  //         long num = (curr - i) / 2;
  //         if(num == 0) {
  //             curr_sol[i] = 1;
  //         } else if(num > 0) {
  //             curr_sol[i] = sol[num][CUMSUM] - sol[num-1][CUMSUM];
  //         }
  //         curr_sol[CUMSUM] += curr_sol[i];
  //     }
  // }

  // compute result
  string result;

  queue<long> q;

  int rem = curr;
  int offset = x - sol[rem - 1][CUMSUM];
  while (rem > 0) {
    auto &curr_sol = sol[rem];

    int i = (rem % 2 == 0) ? 8 : 9;
    int c = 0;
    for (; i >= 0; i -= 2) {
      if (c + curr_sol[i] >= offset) {
        result.push_back('0' + i);
        rem = (rem - i) / 2;
        offset = (offset - c);
        break;
      }
      c += curr_sol[i];
    }
  }

  for (int i = 0; i < result.length() / 2; i++) {
    swap(result[i], result[result.length() - 1 - i]);
  }

  return stol(result);
}

#ifdef CATCH_CONFIG_MAIN

// TEST_CASE("Smaple input 0", "Sample input") {
//     REQUIRE(decibinaryNumbers(1) == 0);
//     REQUIRE(decibinaryNumbers(2) == 1);
//     REQUIRE(decibinaryNumbers(3) == 2);
//     REQUIRE(decibinaryNumbers(4) == 2);     //10
//     REQUIRE(decibinaryNumbers(10) == 4);    // 100
// }

TEST_CASE("Smaple input 1", "Sample input") {
  // REQUIRE(decibinaryNumbers(8)  == to_decimal(12)  );     // 12
  // REQUIRE(decibinaryNumbers(23) == to_decimal(23)  );    // 23
  REQUIRE(decibinaryNumbers(19) == to_decimal(102)); // 102
  REQUIRE(decibinaryNumbers(16) == to_decimal(14));  // 14
  REQUIRE(decibinaryNumbers(26) == to_decimal(111)); // 111
  REQUIRE(decibinaryNumbers(7) == to_decimal(4));    // 4
  REQUIRE(decibinaryNumbers(6) == to_decimal(11));   // 11
}

#else
int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    long x;
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = decibinaryNumbers(x);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}
#endif