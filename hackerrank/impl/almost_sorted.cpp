// https://www.hackerrank.com/challenges/almost-sorted/problem
// implementation, medium

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {

    int u = 0, d = 0;
    int a = -1, b = -1;
    if(arr[0] > arr[1]) {
        d++;
        a = 0;
    }
    for(int i = 1; i < arr.size() - 1; i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            u++;
            if(a == -1) a = i;
        }
        if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
            d++;
            b = i;
        }
    }
    if(arr[arr.size() - 2] > arr[arr.size() - 1]) {
        u++;
        b = arr.size() - 1;
    }

    // cout << "U = " << u << endl;
    // cout << "D = " << d << endl;
    // cout << "A = " << a << endl;
    // cout << "B = " << b << endl;

    if(u == 0 and d == 0){
        cout << "yes" << endl;
        return;
    }

    if(u == 1 && d == 1) {
        if(b - a == 1 || b-a == 2) {
            auto t = arr[b];
            arr[b] = arr[a];
            arr[a] = t;

            if(arr[a] >= arr[a-1] && arr[a] <= arr[a+1]) {
                if(arr[b] >= arr[b-1] && arr[b] <= arr[b+1]) {
                        cout << "yes" << endl;
                        cout << "swap " << a+1 << " " << b+1 << endl;
                        return;
                } 
            } 
        } 
        else {
            if(arr[a+1] < arr[a+2]) {
                cout << "yes" << endl;
                cout << "swap " << a+1 << " " << b+1 << endl;
                return;
            }
            else {
                cout << "yes" << endl;
                cout << "reverse " << a+1 << " " << b+1 << endl;
                return;
            }
        }
    }

    if(u == 2 && d == 2) {
        auto t = arr[b];
        arr[b] = arr[a];
        arr[a] = t;

        if(arr[a] >= arr[a-1] && arr[a] <= arr[a+1]) {
           if(arr[b] >= arr[b-1] && arr[b] <= arr[b+1]) {
                cout << "yes" << endl;
                cout << "swap " << a+1 << " " << b+1 << endl;
                return;
           } 
        } 
    }

    cout << "no" << endl;
    return;


}

int main()
{

    OPEN_INPUT_FILE(fin, "data/input.txt");

    int n;
    fin >> n;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(fin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
