// https://www.hackerrank.com/challenges/append-and-delete/problem
// implementation, easy, 

#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {

    if(k >= (s.size() + t.size()))
        return "Yes";

    // find length of common prefix.
    int p_length = 0;
    while (p_length < s.size() && s[p_length] == t[p_length]) {
        p_length++;
    }

    cout << "Common prefix length :: " << p_length << endl;

    int d = s.size() - p_length;
    int a = t.size() - p_length;

    int op = k - (a+d);
    if( ( (p_length > 0) && (op >= 0) && (op%2 == 0) ) ||
        ( (p_length == 0) && (op > 0) ) ) 
    {
        return "Yes";
    }

    return "No";
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    cout << result << "\n";

    // fout.close();

    return 0;
}
