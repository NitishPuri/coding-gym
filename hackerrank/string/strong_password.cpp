// https://www.hackerrank.com/challenges/strong-password/problem
// string, easy

#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string special_characters = "!@#$%^&*()-+";
    auto isspecial = [&special_characters](char ch){
        return (special_characters.find(ch) != string::npos);
    };

    bool digit = false;
    bool lower = false;
    bool upper =false;
    bool special = false;
    bool count = false;
    for(auto p : password) {
        if(digit && lower && upper && special) break;

        if(!digit && isdigit(p)) digit = true;
        if(!lower && islower(p)) lower = true;
        if(!upper && isupper(p)) upper = true;
        if(!special && isspecial(p)) special = true;
    }

    int c = 0;
    if(!digit) c++;
    if(!lower) c++;
    if(!upper) c++;
    if(!special) c++;

    if(n+c < 6) {
        c += 6 - (n+c);
    }

    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
