// https://leetcode.com/problems/throne-inheritance/
// medium, hash-table, tree, depth-first-search, design

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class ThroneInheritance {
    string king;
    
    struct Heir {
        string name;
        bool is_alive = true;
        vector<Heir*> children;
    };
    
    unordered_map<string, Heir*> m;
    
    void preOrder(Heir* heir, vector<string>& succession) {        
        if(heir->is_alive) {
            succession.push_back(heir->name);
        }           
        for(auto& child : heir->children) {
            preOrder(child, succession);
        }            
    }
    
public:
    ThroneInheritance(string kingName) {
        king = kingName;
        m[king] = new Heir{king};
    }
    
    void birth(string parentName, string childName) {
        m[childName] = new Heir{childName};
        m[parentName]->children.emplace_back(m[childName]);
    }
    
    void death(string name) {
        m[name]->is_alive = false;
    }
    
    vector<string> getInheritanceOrder() {        
        vector<string> succession;        
        preOrder(m[king], succession);                
        return succession;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */