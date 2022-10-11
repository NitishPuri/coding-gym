// https://www.hackerrank.com/challenges/manasa-and-stones/problem
// implementation, easy

#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {

    if(a == b) return {(n-1)*a};

    vector<int> result;
    result.reserve(n);

    int s = min(a, b);
    int g = max(a, b);

    for(int i = 0; i < n; i++) {
        result.push_back(i*g + (n-i-1)*s);
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
