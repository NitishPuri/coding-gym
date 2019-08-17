// https://www.hackerrank.com/challenges/beautiful-binary-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {

    int moves = 0;
    string p = "010";
    size_t f = 0;
    while(true) {
        f = b.find(p, f);
        if(f == string::npos) break;
        moves++;
        f += p.length();
    }

    return moves;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
