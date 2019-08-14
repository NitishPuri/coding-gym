// https://www.hackerrank.com/challenges/strange-code/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long initial = 3;
    long curr_t = 1;

    while(curr_t+initial <= t) {
        curr_t += initial;
        initial *= 2;
    }

    return initial - (t - curr_t);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
