// https://www.hackerrank.com/challenges/kaprekar-numbers/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    bool found = false;
    for(long i = p; i <= q; ++i) {
        long square = i*i; 
        string s = to_string(square);
        auto d = s.length() / 2;
        auto l = (d == 0) ? 0 : stol(s.substr(0, d)) ;
        auto r = stol(s.substr(d, string::npos));
        if(l+r == i) {
            found = true;
            cout << i << " ";
        }
    }

    if(found == false) cout << "INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
