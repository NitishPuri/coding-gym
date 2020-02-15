#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

#define and &&

#define OPEN_INPUT_FILE(s, f)                                                  \
  ifstream s(f);                                                               \
  if (!s.is_open()) {                                                          \
    cout << "Could not open " << f << endl;                                    \
    getchar();                                                                 \
    return 0;                                                                  \
  }
