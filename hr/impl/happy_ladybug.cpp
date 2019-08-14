// https://www.hackerrank.com/challenges/happy-ladybugs/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    map<char, int> colors;
    bool has_empty = false;

    for(int i = 0; i < b.length(); i++) {
        if(b[i] == '_') {
            has_empty = true; 
            continue;
        }
        colors[b[i]]++;
    }
    
    if(!has_empty) {

        // check if everyone is already happy?
        bool is_happy = true;

        if(b[0] != b[1]) is_happy = false;
        for(int i = 1; (i < b.length() - 1) && (is_happy == true); ++i) {
            if( (b[i-1] != b[i]) && (b[i] != b[i+1]) ) is_happy = false;
        }
        if(is_happy && (b[b.length()-2] != b[b.length()-1]) ) is_happy = false;

        if(is_happy) return "YES";

        return "NO";
    }

    for(auto c : colors) {
        if(c.second == 1) return "NO";
    }

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
