// https://www.hackerrank.com/challenges/cavity-map/problem
// implementation, easy

#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(const vector<string>& grid) {

    int n = grid.size();

    auto grid_c = grid;

    auto get_depth = [&grid](int i, int j) {
        return (grid[i][j] - '0');
    };

    for(int i = 1; i < n - 1; ++i) {
        for(int j = 1; j < n-1; ++j) {                        
            auto d = get_depth(i, j);
            if(d > get_depth(i-1, j) &&
               d > get_depth(i, j-1) &&
               d > get_depth(i+1, j) &&
               d > get_depth(i, j+1)) {
                   grid_c[i][j] = 'X';
               }
        }
    }

    return grid_c;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
