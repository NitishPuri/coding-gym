#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Tag {
    Tag(string name) {
        _name = name;
    }

    ~Tag() {
        cout << "Deleting tag :: " << _name << endl;
        while (!childTags.empty()){
            Tag* child = childTags.at(childTags.size() - 1);
            childTags.pop_back();
            delete child;
        }
    }

    Tag* addTag(string name) {
        Tag* tag = new Tag(name);
        childTags.push_back(tag);
        return tag;
    }

private:
    vector<Tag*> childTags;
    string _name;
    map<string, string> _attributes;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N;  // Number of HRML lines (< 20)
    int Q;  // Number of queries    (< 20)

    cin >> N >> Q;
//    cout << N << endl << Q << endl;

    cin.ignore();

    //! Read lines
    //cout << "Reading lines" << endl;
    string lines[20];
    for (int i = 0; i < N; ++i) {
        char s[256];
        cin.getline(s, 256);
        //cout << "Line " << i << ":::: " << s << endl;
        lines[i] = s;
    }

    //cout << "Reading queries" << endl;

    //! Read queries
    string queries[20];
    for (int i = 0; i < Q; ++i) {
        char s[256];
        cin.getline(s, 256);
        //cout << "Line " << i << ":::: " << s << endl;
        queries[i] = s;
    }

    //cout << "Output,.." << endl;

    for (int i = 0; i < N; ++i) {
        
        cout << lines[i] << endl;
    }
    for (int i = 0; i < Q; ++i) {
    cout << queries[i] << endl;
    }


    
    return 0;
}
