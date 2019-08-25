#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {

    vector< vector<int> > ab(a.length()+1, vector<int>(b.length()+1, 0));

    auto printVec = [&](){
        for(auto b : ab) {
            for(auto j : b) {
                cout << j << " , ";
            }
            cout << endl;
        }
    };


    ab[0][0] = 1;

    bool contains_cap = false;
    for(int i = 1; i <= a.length(); ++i) {
        if(isupper(a[i-1]) || contains_cap) {
            contains_cap = true;
            ab[i][0] = 0;
        } else {
            ab[i][0] = 1;
        }
    }

    printVec();

    for(int i = 1; i <= a.length(); ++i) {
        for(int j = 1; j <= b.length(); ++j) {
            if(isupper(a[i-1])) {
                if(a[i-1] == b[j-1]) {
                    ab[i][j] = ab[i-1][j-1];
                } else {
                    ab[i][j] = 0;
                }
            } else {
                if(toupper(a[i-1]) == b[j-1]) {
                    ab[i][j] = ab[i-1][j-1] || ab[i-1][j];
                } else {
                    ab[i][j] = ab[i-1][j];
                }
            }
            cout << "i = " << i << " , j = " <<  j << endl;
            printVec();
        }
    }

    return (ab[a.length()][b.length()] == 1) ? "YES" : "NO";
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        cout << result << "\n";
    }

    // fout.close();

    return 0;
}
