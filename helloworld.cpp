#include <iostream>
#include <string>
#include <vector>

using namespace std;

// test compiler
int main() {
  vector<string> msg{"Hello", "C++", "World", "from", "VS Code!"};

  for (const string &word : msg) {
    cout << word << " ";
  }
  cout << endl;
}
