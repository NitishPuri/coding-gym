// https://www.hackerrank.com/challenges/palindrome-index/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {

    auto is_palindrome = [&](int start, int end) {
        for(; start < end; start++, end--) {
            if(s[start] != s[end]) return false;
        }
        return true;
    };

    for(int i = 0, j = s.length()-1; i < j; ++i, --j) {
        if(s[i] != s[j]) {
            // skip i
            if(is_palindrome(i+1, j)) return i;
            // skip j
            if(is_palindrome(i, j-1)) return j;

            // neither worked.
            return -1;
        }
    }

    return -1;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        cout << result << "\n";
    }

    // fout.close();

    return 0;
}
