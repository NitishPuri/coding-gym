// https://www.hackerrank.com/challenges/bigger-is-greater/problem
// implementation, easy

#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {

    if(w.length() < 2) {
        return "no answer";
    }

    // find the point break;
    int k = w.length() - 2;
    for(; k >= 0; k--) {
        if(w[k+1] > w[k]) break;        
    }
    if(k == -1) return "no answer";

    multiset<char> s;
    for(int i = k; i < w.length(); ++i) s.insert(w[i]);

    auto itr = s.upper_bound(w[k]);
    if(itr == s.end()) return "no answer";
    
    while(!s.empty()) {
        w[k++] = *itr;
        s.erase(itr);
        itr = s.begin();
    }

    return w;
}

int main()
{

    // biggerIsGreater("bb");
    // return 0;
    
    OPEN_INPUT_FILE(f_input, "data/input.txt");

    OPEN_INPUT_FILE(f_result, "data/result.txt");
        
    int T;
    f_input >> T;
    f_input.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(f_input, w);

        string w_res;
        getline(f_result, w_res);

        string result = biggerIsGreater(w);

        // compare result and w_res
        if(result.compare(w_res) != 0) {
            cout << "----------------------------------------------------"<< endl;
            cout << w << endl << endl;
            cout << w_res << endl;
            cout << "----------------------------------------------------"<< endl;
        }

        // cout << result << "\n";
    }

    // cout.close();

    f_input.close();
    f_result.close();

    getchar();
    return 0;
}
