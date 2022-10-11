// https://www.hackerrank.com/challenges/queens-attack-2/problem
// implementation, medium

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    
    auto offset = [](int d, int q, int n) {
        int o;
        if(d == -1) o = q - 1;
        else if(d == 0) o = INT_MAX;
        else if(d == 1) o = n - q;
        return o;
    };

    map< pair<int, int>, int> dirs; 
    for(int dr = -1; dr <= 1; ++dr) {
        int ro = offset(dr, r_q, n);
        for(int dc = -1; dc <= 1; ++dc) {
            int co = offset(dc, c_q, n);
            if(dc != 0 || dr != 0)
                dirs[{dr, dc}] = min(ro, co);
        }
    }

    auto signum = [](int a){ return (0 < a) - (a < 0); };

    for(auto& o : obstacles) {
        int r = o[0] - r_q;
        int c = o[1] - c_q;
        if(r == 0 || c == 0 || (abs(r) == abs(c))) {
            // obstacle will be hit.
            auto& dir = dirs[{signum(r), signum(c)}];
            dir = min(max(abs(r), abs(c)) - 1, dir);
        }
    }

    int count = 0;
    for(const auto& dir : dirs) count += dir.second;

    return count;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    cout << result << "\n";

    // fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
