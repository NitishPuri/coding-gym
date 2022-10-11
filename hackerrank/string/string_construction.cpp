// https://www.hackerrank.com/challenges/string-construction/problem
// string, easy

#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    int cost = 0;
    set<char> f;
    for(auto c : s) {
        auto itr = f.find(c);
        if(itr == f.end()) {
            cost++;
            f.insert(c);
        }
    }

    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
