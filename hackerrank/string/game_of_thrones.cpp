// https://www.hackerrank.com/challenges/game-of-thrones/problem
// string, easy

#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {

    map<char, int> count;
    for(auto c : s) { count[c]++; }

    if(s.length() % 2 == 0) {
        // even
        for(auto c : count) {
            if(c.second % 2 != 0) return "NO";
        }
    } else {
        // odd
        bool odd_allowed = true;
        for(auto c : count) {
            if(c.second % 2 != 0) {
                if(odd_allowed) {
                    odd_allowed = false;
                } else {
                    return "NO";
                }
            }
        }
    }

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
