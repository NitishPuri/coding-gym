// https://www.hackerrank.com/challenges/reduced-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {

    while(true) {
        bool operated = false;
        stringstream ss;
        int i = 0;
        for(; i < s.length()-1; i++) {
            if(s[i] == s[i+1]) {
                i++;
                operated = true;
            } else {
                ss << s[i];
            }
        }

        if(i == s.length() - 1) ss << s[i];

        if(!operated) break;

        s = ss.str();
        if(s.empty()) {
            s = "Empty String";
            break;
        }
    }

    return s;

}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    cout << result << "\n";

    // fout.close();

    return 0;
}
