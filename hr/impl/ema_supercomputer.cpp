// https://www.hackerrank.com/challenges/two-pluses/problem
// implementation, medium

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {

    int h = grid.size();
    int w = grid[0].size();

    int max_size = min(w, h);
    if(max_size%2 == 0) max_size--;

    vector< vector<int> > grid_i(grid.size(), vector<int>(grid[0].size()));

    auto is_good = [&](int i, int j){
        if(i < 0 || i >= h) return false;
        if(j < 0 || j >= w) return false;
        if(grid[i][j] == 'B') return false;
        return true;
    };

    using Plus = pair<int, int>;
    vector<Plus> candidate_plus;

    int max_l = 0, s_max_l = 0;
    for(int i = 1; i < h-1; i++) {
        for(int j = 1; j < w-1; j++) {
            if(grid[i][j] == 'B') continue;
            grid_i[i][j] = 1;
            auto d = 1;
            while(true) {
                auto t = is_good(i-d, j);
                auto b = is_good(i+d, j);
                auto l = is_good(i, j-d);
                auto r = is_good(i, j+d);
                if(!t || !b || !l || !r) break;
                d++;
            }
            grid_i[i][j] = d;            
            candidate_plus.push_back({i, j});
        }
    }

    auto area = [](int l) { return (l-1)*4 + 1; };

    auto overlaps = [](Plus p1, int s1, Plus p2, int s2) {
        set< pair<int, int> > set_1;
        set_1.insert(p1);
        for(int i = 1; i < s1; i++) {
            set_1.insert({p1.first - i, p1.second});
            set_1.insert({p1.first + i, p1.second});
            set_1.insert({p1.first, p1.second - i});
            set_1.insert({p1.first, p1.second + i});
        }

        if(set_1.find(p2) != set_1.end()) return true;
        for(int i = 1; i < s2; ++i) {
            if(set_1.find({p2.first - i, p2.second}) != set_1.end()) return true;
            if(set_1.find({p2.first + i, p2.second}) != set_1.end()) return true;
            if(set_1.find({p2.first, p2.second - i}) != set_1.end()) return true;
            if(set_1.find({p2.first, p2.second + i}) != set_1.end()) return true;
        }

        return false;
    };

    int max_area = 0;

    auto get_plus_size = [&grid_i](Plus p) { return grid_i[p.first][p.second]; };

    for(int i = 0; i < candidate_plus.size(); ++i) {
        for(int j = i+1; j < candidate_plus.size(); ++j) {
            auto& pi = candidate_plus[i];
            auto& pj = candidate_plus[j];

            // Check for all values of plusses
            auto si = get_plus_size(pi);            
            while(si >= 1) {
                auto sj = get_plus_size(pj);
                while(sj >= 1) {
                    auto p = area(si)*area(sj);
                    if(p > max_area  &&  !overlaps(pi, si, pj, sj)) {
                        max_area = p;
                    }
                    sj--;
                }
                si--;
            }
        }
    }


    return max_area;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    cout << result << "\n";

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
