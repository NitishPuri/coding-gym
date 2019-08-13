#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
#include <numeric>
#include <functional>
#include <queue>
#include <map>
#include <sstream>

#define and &&

#define OPEN_INPUT_FILE(s, f) ifstream s(f); \
    if(!s.is_open()) {                       \
        cout << "Could not open " << f << endl; \
        getchar(); return 0; }               \
