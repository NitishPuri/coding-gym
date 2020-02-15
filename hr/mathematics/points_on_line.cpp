#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::set<int> x;
    std::set<int> y;

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        x.insert(stoi(xy[0]));
        y.insert(stoi(xy[1]));

        if(x.size() > 1 && y.size() > 1) {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";

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
