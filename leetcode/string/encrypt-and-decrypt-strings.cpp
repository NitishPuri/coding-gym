// https://leetcode.com/problems/encrypt-and-decrypt-strings/
// array, hash-table, string, design, trie, hard
// a  b  c  z
// aa bb cc zz
// aa aaa aaaa aaaaa aaaaaa

// aaaa -> aa -> 1
// aa -> a -> 0

#include <unordered_map>
using namespace std;

class Encrypter {
    
    // struct Trie {
    //     // char key;
    //     bool wordend = false;
    //     unordered_map<char, Trie*> children;
    // };    
    // void trie_insert(Trie* t, const string& s, int start = 0) {        
    //     if(start == s.length()) {
    //         t->wordend = true;
    //         return;
    //     }                
    //     if(t->children.find(s[start]) == t->children.end()) {
    //         t->children[s[start]] = new Trie;
    //     }        
    //     trie_insert(t->children[s[start]], s, start + 1);                        
    // }        
    // bool trie_find(Trie* t, const string& s, bool partial, int start = 0) {                
    //     if(start == s.length()) return partial ? true : t->wordend;        
    //     auto itr = t->children.find(s[start]);
    //     if(itr == t->children.end()) return false;        
    //     return trie_find(itr->second, s, partial, start + 1);                
    // }
    
    
    //unordered_set<string> dict;     // can use a trie instead of hash-table.
    // Trie t;
    unordered_map<char, string> value;
    // unordered_map<string, vector<char>> keys;
    unordered_map<string, int> dict; // encrypted dictionary
    
                
public:
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        int n = k.size();
        for(int i = 0; i < n; ++i) {
            value[k[i]] = v[i];
            // keys[v[i]].push_back(k[i]);
        }
        
        // using a unordered_set as dictionary
        // for(auto& s: d) {
        //     dict.insert(s);
        // }
        
        // using a trie as dictionary
        // for(auto& s : d) {
        //     trie_insert(&t, s);
        // }                        
        
        // use an encrypted dictionary
        for(auto w : d) {
            dict[encrypt(w)] += 1;
        }
    }
    
    string encrypt(string word1) {
        string res;
        for(auto c : word1) {
            auto itr = value.find(c);
            if(itr == value.end()) return "";
            res += itr->second;
        }
        return res;
    }
    
    // using encrypted dictionary
    int decrypt(string word2) {
        return dict[word2];
    }
    
// using a unordered_set as dictionary    
//     int decrypt(string word2) {
//         int n = word2.size();
//         if(n & 1) return 0;
//         string s = "aa";
//         vector<string> words;
//         words.push_back("");
//         for(int i = 0; i < n; i += 2) {
//             s[0] = word2[i];
//             s[1] = word2[i+1];
//             auto itr = keys.find(s);
//             if(itr == keys.end()) return 0;
                
//             int word_len = words.size();
//             for(int j = 0; j < itr->second.size(); ++j) {                                
//                 for(int k = 0; k < word_len; ++k) {
//                     if(j == 0) {
//                         words[k] = words[k] + itr->second[0];    
//                     } else {
//                         string st = words[k];
//                         st[st.length() - 1] = itr->second[j];
//                         words.push_back(st);
//                     }                    
//                 }                                
//             }                        
//         }
        
//         int res = 0;
//         for(auto& word : words) {
//             if(dict.find(word) != dict.end()) ++res;
//         }
                
//         return res;
//     }
    
    // using a trie as dictionary
//     int decrypt(string word2) {
//         int n = word2.size();
//         if(n & 1) return 0;
//         string s = "aa";
        
        
//         vector<string> words;
//         words.push_back("");
        
        
//         for(int i = 0; i < n; i += 2) {
//             s[0] = word2[i];
//             s[1] = word2[i+1];
//             auto itr = keys.find(s);
//             if(itr == keys.end()) return 0;
                
//             int word_len = words.size();
//             vector<string> new_words;
//             for(int j = 0; j < itr->second.size(); ++j) {                                
//                 for(int k = 0; k < word_len; ++k) {
//                     string w = words[k] + itr->second[j];
//                     if(trie_find(&t, w, (i < n -2) )) {
//                         new_words.push_back(w);
//                     }                        
//                 }                                
//             }
//             words = new_words;
//         }
        
//         return words.size();        
//     }
    
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */