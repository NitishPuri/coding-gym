// https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem
// greedy, hard

#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s)
{

    int l = s.length() / 2;
    map<char, float> m;
    for (const auto &c : s)
    {
        m[c] += 0.5;
    }
    auto printMap = [](string name, const map<char, float> &mp) {
        cout << name << " ==> ";
        for (auto &cm : mp)
        {
            cout << cm.first << " : " << cm.second << " , ";
        }
        cout << endl;
    };

    printMap("Frequency", m);

    auto ms = m;

    string result;
    result.reserve(l);

    const auto get_smallest = [](const map<char, float> &mp) {
        for (auto &cm : mp)
        {
            if (cm.second > 0)
                return cm.first;
        }
        return char('a' - 1);
    };

    // auto smallest = m.begin()->first;
    auto smallest = get_smallest(m);
    char best_seen = 'z' + 1;
    auto best_index = s.rend();

    for (auto itr = s.rbegin(); itr < s.rend(); itr++)
    {
        // auto cur = *itr;

        const auto printInfo = [&](string section) {
            cout << "IN " << section << " :: " << endl;
            cout << "Current : " << *itr;
            cout << "  ,  Smallest : " << smallest;
            cout << "  ,  Best : " << best_seen << endl;

            auto itrp = s.rbegin();
            for (; itrp <= itr; itrp++)
                cout << *itrp;
            cout << "  ";
            for (; itrp < s.rend(); itrp++)
                cout << *itrp;
            cout << endl;

            cout << "Result : " << result;
            cout << endl;

            printMap("Taken   : ", m);
            printMap("Skipped : ", ms);

            cout << "--------------------------------------" << endl;
        };

        if (*itr <= smallest)
        {
            //
            if (m[*itr] > 0)
            {
                result.push_back(*itr);
                m[*itr]--;
                smallest = get_smallest(m);
                best_seen = 'z' + 1;
                printInfo("Selecting Smallest");
            }
            else
            {
                ms[*itr]--;
                printInfo("Nothing to do, Skipping.");
            }
        }
        else
        {
            //
            if (ms[*itr] > 0)
            {
                ms[*itr]--;
                if (*itr < best_seen && m[*itr] > 0)
                {
                    best_seen = *itr;
                    best_index = itr;
                }
                printInfo("Skipping, Updated best seen");
            }
            else
            {
                if (*itr < best_seen)
                {
                    result.push_back(*itr);
                    m[*itr]--;
                    smallest = get_smallest(m);
                    best_seen = 'z' + 1;
                    printInfo("Has to be selected.");
                }
                else
                {
                    while (itr > best_index)
                    {
                        cout << "Processing : " << *itr;
                        cout << " Going back to : " << best_seen << endl;
                        itr--;
                        ms[*itr]++;
                    }
                    result.push_back(*itr);
                    m[*itr]--;
                    smallest = get_smallest(m);
                    best_seen = 'z' + 1;
                    printInfo("Looping back to best seen.");
                }
            }
        }
    }

    return result;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    cout << result << "\n";

    // fout.close();
    getchar();

    return 0;
}
