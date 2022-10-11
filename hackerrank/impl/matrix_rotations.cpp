// https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
// implementation, hard, matrix, 

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    auto matrix_copy = matrix; // copy

    auto h = matrix.size();
    auto w = matrix[0].size();

    auto c_y = float(h) / 2.0;  // 5
    auto c_x = float(w) / 2.0;  // 4
    auto y_x = c_y - c_x;       // 1

    using p_c_i = pair<char, int>;
    vector< vector<p_c_i> > dir(h, vector<p_c_i>(w));

    map<int, int> cycles;

    for(int j = 0; j < h; ++j) {
        // cout << showpos;
        // for(int k = 0; k < w; ++k) {
        //     auto a = c_y - (j+0.5);
        //     auto b = c_x - (k+0.5);
        //     cout << "(" << a << "," << b << ") "; 
        // }
        // cout << "\t";
        // cout << noshowpos;
        for(int k = 0; k < w; ++k) {
            auto a = c_y - (j+0.5);
            auto b = c_x - (k+0.5);
            
            auto& d = dir[j][k].first;
            auto&c = dir[j][k].second;
            
            c = ceil(max(abs(a) - y_x, abs(b)));
            cycles[c]++;

            auto a_b = (abs(a) - abs(b));

            if( a_b == y_x ) { // corner.
                if(a > 0) {
                    d = (b > 0) ? 'r' : 'd';
                }
                else if(a < 0) {
                    d = (b > 0) ? 'u' : 'l';
                }
            }
            else if(a_b > y_x) {
                d = (a > 0 ? 'r' : 'l');
            }
            else {
                d = (b > 0 ? 'u' : 'd');
            }

            // cout << c << " ";
        }
        // cout << "\t";
        // for(auto d : dir[j]) cout << d.first << " ";
        // cout << endl;        
    }

    // cout << "..............................." << endl;

    auto& source = matrix;
    auto& destination = matrix_copy;

    for(int j = 0; j < h; j++) {
        for(int k = 0; k < w; k++) {
            auto c = dir[j][k].second;

            auto c_count = cycles[c];
            auto r_c = r % c_count;

            auto sj = j, sk = k;
            for(int i = 0; i < r_c; i++) {
                switch (dir[sj][sk].first)
                {
                case 'l':
                    sk--; break;
                case 'r':
                    sk++; break;
                case 'u':
                    sj--; break;
                case 'd':
                    sj++; break;
                default:
                    break;
                }
            }
            destination[j][k] = source[sj][sk];
        }

    for(auto de : destination[j]) cout << de << " ";
    cout << endl;
        
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
