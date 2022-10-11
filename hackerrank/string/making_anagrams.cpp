// https://www.hackerrank.com/challenges/making-anagrams/problem
// string easy

#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {

    multiset<char> f;
    for(auto c : s1) {
        f.insert(c);
    }

    int count = 0;
    for(auto c : s2) {
        auto itr = f.find(c);
        if(itr == f.end()) {
            count++;
        } else {
            f.erase(itr);
        }
    }

    return count + f.size();
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    cout << result << "\n";

    getchar();

    // fout.close();

    return 0;
}