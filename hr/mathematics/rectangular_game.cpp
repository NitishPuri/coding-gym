#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
int solve(vector<vector<int>> steps) {

    if(steps.empty()) {
        return 0;
    }

    int x = INT_MAX
    int y = INT_MAX
    for(auto step : steps) {
        if( step[0] < x) {
            x = step[0];
        }
    }


    int max_yet = 0;
    for(auto step : steps) {
        cout << "Processing " << step[0] << " " << step[1] << endl;
        for(int i = 1; i <= step[0]; i++) {
            for(int j = 1; j <= step[1]; j++) {
                coord c{i, j};
                if(coords.find(c) == coords.end()) {
                    coords[c] = 1;
                } else {
                    coords[c]++;
                }
                if(coords[c] > max_yet) {
                    max_yet = coords[c];
                }
            }
        }
        cout << "Max Yet " << max_yet << endl;
    }

    int max_count = 0;
    for(auto coord : coords) {
        if(coord.second == max_yet) {
            max_count++;
        }
    }

    return max_count;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;

    cout << "Hello!!\n";

    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> steps(n);
    for (int steps_row_itr = 0; steps_row_itr < n; steps_row_itr++) {
        steps[steps_row_itr].resize(2);

        for (int steps_column_itr = 0; steps_column_itr < 2; steps_column_itr++) {
            cin >> steps[steps_row_itr][steps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = solve(steps);

    std::cout << result << "\n";

    // fout.close();

    return 0;
}
