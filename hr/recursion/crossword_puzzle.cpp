// https://www.hackerrank.com/challenges/crossword-puzzle/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Gaps{
    int length;
    int x;
    int y;
    int dir;    // 0 -- horizontal, 1 -- vertical
};

void findGaps(char (&mat)[10][10], multimap<int, Gaps>& v){
    
    int s = -1;
    int c = 0;
    // horizontal pass.    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(mat[i][j] == '-'){
                if(s == -1){
                    s = j;
                    c = 1;                    
                    //cout << "i:: " << i << " s::" << s << " c:: " << c << endl;
                }
                else{
                    c++;
                    //cout << "i:: " << i << " s::" << s << " c:: " << c << endl;
                }
            }
            else{
                if((s > -1) && (c > 1)){
                    v.insert(make_pair(c, Gaps{c, i, s, 0}));
                }
                s = -1;
                c = 0;
            }
        }
        if((s > -1) && (c > 1)){
            v.insert(make_pair(c, Gaps{c, i, s, 0}));
        }
        s = -1;
        c = 0;        
    }

    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            if(mat[i][j] == '-'){
                if(s == -1){
                    s = i;
                    c = 1;                    
                    //cout << "i:: " << i << " j::" << j << " c:: " << c << endl;
                }
                else{
                    c++;
                    //cout << "i:: " << i << " j::" << j << " c:: " << c << endl;
                }
            }
            else{
                if((s > -1) && (c > 1)){
                    v.insert(make_pair(c, Gaps{c, s, j, 1}));
                }
                s = -1;
                c = 0;
            }
        }
        if((s > -1) && (c > 1)){
            v.insert(make_pair(c, Gaps{c, s, j, 1}));
        }
        s = -1;
        c = 0;
    }        
}

void fillWord(char (&mat)[10][10], string w, Gaps g){
//    cout << g.x << "  " << g.y << "  " << g.dir << endl;
    if(g.dir == 0){
        int i = g.x;
        for(int j = g.y; j < g.y + g.length; j++){
            mat[i][j] = w[j - g.y];
        }
    }
    else{
        int j = g.y;
        for(int i = g.x; i < g.x + g.length; i++){
            mat[i][j] = w[i - g.x];
        }
    }        
}

bool canFill(char (&mat)[10][10], string w, Gaps g){
    if(g.dir == 0){
        int i = g.x;
        for(int j = g.y; j < g.y + g.length; j++){
            if((mat[i][j] != '-') && (mat[i][j] != w[j-g.y])) {
                return false;
            }
        }
    }
    else{
        int j = g.y;
        for(int i = g.x; i < g.x + g.length; i++){
            if((mat[i][j] != '-') && (mat[i][j] != w[i-g.x])) {
                return false;
            }
        }
    }           
    return true;
}

void printMat(char (&mat)[10][10]){
    //cout << "::::"<< endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
    //cout << "::::"<<endl;
}
void printGap(Gaps g){
    cout << "Gap::(L:" << g.length << ") ; (X:" << g.x << 
        ") ; (Y:"<<g.y << ") ; (D:"<< g.dir << ");"<< endl; 
}

void fillWords(char (&mat)[10][10], vector<string> words, multimap<int, Gaps> gaps){
    if(words.size() == 0) return;
    
    
    while(words.size() > 0){
        //cout << "Words left :: " << words.size() << endl;
        vector<string> w2;
        for (auto w : words){
            //cout << "Trying to fill :: " << w << endl;
            auto ret = gaps.equal_range(w.size());
            int c = 0;
            Gaps g;
            for(auto it = ret.first; it != ret.second; ++it){
                if(canFill(mat, w, it->second)){
                    //cout << "Can fill in gap :: "; printGap(it->second);
                    c++;
                    g = it->second;
                }        
                else{
                    //cout << "Can't fill in gap :: "; printGap(it->second);
                }
            }
            //cout << "c :: " << c << endl ;
            if(c == 1){
                //cout << "Filling word " << w << endl;
                fillWord(mat, w, g);
                //printMat(mat);
            }
            else{
                w2.push_back(w);
            }
        }
        words = w2;        
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char mat[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> mat[i][j];
        }
    }
    
    string words;
    cin >> words;
    size_t pos;
    vector<string> word;
    while((pos = words.find(';')) != std::string::npos){
        word.push_back(words.substr(0, pos));
        words.erase(0, pos + 1);
    }
    word.push_back(words);    
    
    //for(auto w : word) cout << w << endl;
    
    multimap<int, Gaps> v;
    findGaps(mat, v);
    
    //printMat(mat);
    
    //for(auto g : v) printGap(g.second);
    
    vector<string> w2;
    for(auto w : word){
        if(v.count(w.size()) == 1){
            //cout << "Filling word " << w << endl;
            fillWord(mat, w, v.find(w.size())->second);         
            v.erase(w.size());
        }
        else{
            w2.push_back(w);
        }
    }

    //for(auto g : v) printGap(g.second);
    
    //printMat(mat);
    
    fillWords(mat, w2, v);
    
    printMat(mat);
    
                
    return 0;
}
