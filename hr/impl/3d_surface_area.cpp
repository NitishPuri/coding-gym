// https://www.hackerrank.com/challenges/3d-surface-area/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    int H = A.size();
    int W = A[0].size();

    int area = 2*H*W; // bottom + top

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int h = A[i][j];
            int n = (i == 0)   ? 0 : A[i-1][j]; // north height
            int s = (i == H-1) ? 0 : A[i+1][j]; // south height
            int e = (j == 0)   ? 0 : A[i][j-1]; // east height
            int w = (j == W-1) ? 0 : A[i][j+1]; // west height

            area += max(h - n, 0);  // north
            area += max(h - s, 0);  // south
            area += max(h - e, 0);  // east
            area += max(h - w, 0);  // west
        }
    }

    return area;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

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
