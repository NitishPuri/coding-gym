// https://www.hackerrank.com/challenges/bomber-man/problem
// implementation, medium

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {

    // nothing happens!
    if(n < 2) return grid;

    if(n%2 == 0) {
        // Everything will be a bomb!
        for(auto& row : grid) {
            for(auto& cell : row) {
                cell = 'O';
            }
        }
        return grid;
    }


    for(auto& row : grid) {
        for(auto& cell : row) {
            if(cell == 'O') cell = '2';
        }
    }

    if (n%4 == 3) n = 3;    // Pattern repeats for 3, 7, 11, 15,...
    if (n%4 == 1) n = 5;    // Pattern repeats for 5, 9, 13, 17,...

    int curr = 2;
    while(curr <= n) {
        auto plant = (curr%2 == 0);
        for(int i = 0; i < grid.size(); ++i) {
            auto& row = grid[i];
            for(int j = 0; j < row.size(); ++j) {
                auto& cell = row[j];
                if(plant && cell == '.') cell = '3';    // plant
                else if(cell != '.'){
                    // decrement timer.
                    cell--;
                    if(cell == '0') {
                        // exlode.
                        cell = '.';
                        if(j != 0) row[j-1] = '.';
                        if(j != row.size() - 1 && row[j+1] != '1') row[j+1] = '.';
                        if(i != 0) grid[i-1][j] = '.';
                        if(i != grid.size() - 1 && grid[i+1][j] != '1') grid[i+1][j] = '.';
                    }
                }
            }
        }
        curr++;
    }

    for(auto& row : grid) {
        for(auto& cell : row) {
            if(cell != '.') cell = 'O';
        }
    }

    return grid;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
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
