// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
// medium, implementation

#include <bits/stdc++.h>
// #include
// #include <set>
using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(const vector<vector<int>>& container) {

    vector<int> count_of_each_type(container.size(), 0);
    multiset<int> count_in_container;

    for(int c = 0; c < container.size(); ++c) {
        const auto& cont = container[c];
        int curr_count_in_container = 0;
        for(int b = 0; b < cont.size(); ++b) {
            curr_count_in_container += cont[b];
            count_of_each_type[b] += cont[b];
        }

        count_in_container.insert(curr_count_in_container);
    }

    for(auto c : count_of_each_type) {
        auto itr = count_in_container.find(c); 
        if(itr == count_in_container.end()) {
            return "Impossible";
        }
        
        count_in_container.erase(itr);
    }

    return "Possible";
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        cout << result << "\n";
    }

    // cout.close();

    return 0;
}
