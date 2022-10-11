// https://www.hackerrank.com/challenges/anagram/problem
// string, easy

#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    const auto n = s.length();
    if(n & 1) return -1;

    const auto n_2 = n /2;
    size_t i = 0;
    multiset<char> f;
    for(; i < n_2; ++i) { f.insert(s[i]); }
    for(; i < n  ; ++i) { 
        auto itr = f.find(s[i]);
        if( itr != f.end() ) {
            f.erase(itr); 
        }
    }

    return f.size();
}

int main()
{
    while(true) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        cout << result << "\n";

    }

    // getchar();

    return 0;
}
