// https://www.hackerrank.com/challenges/acm-icpc-team/problem
// implementation, easy

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic) {

    auto combine = [](const string& m1, const string& m2) {
        int c = 0;
        for(int i = 0; i < m1.length(); ++i) {
            if(m1[i] == '1' || m2[i] == '1') {
                c++;
            }
        }
        return c;
    };

    int max_topics = 0;
    int max_count = 0;
    for(int i = 0; i < topic.size(); ++i) {
        for(int j = i+1; j < topic.size(); ++j) {
            int c = combine(topic[i], topic[j]);
            if(c > max_topics) {
                max_topics = c;
                max_count = 1;
            } else if(c == max_topics) {
                max_count++;
            }
        }
    }

    return {max_topics, max_count}; 
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

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
