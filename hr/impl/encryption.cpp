// https://www.hackerrank.com/challenges/encryption/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    double l = sqrt(s.length());
    int r = floor(l);
    int c = ceil(l);

    if(c*r < s.length()) r++;

    stringstream result;

    int ri = 0, ci = 0;
    while(true) {
        auto t = ri * (c) + ci;
        if(t < s.length()) result << s[t];
        ri++;
        if(ri == r) {
            ri = 0; ci++;
            if(ci == c) break;
            result << " ";
        }
    }

    return result.str();
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    // fout.close();

    return 0;
}
