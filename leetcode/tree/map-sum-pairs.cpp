// https://leetcode.com/problems/map-sum-pairs
// medium, hash-table, string, design, trie

#include <unordered_map>
#include <stack>
using namespace std;

class MapSum {
    struct Node {
        int val = 0;        
        unordered_map<char, Node*> children;        
    };
    
    Node* root = nullptr;
public:
    MapSum() {
        root = new Node;
    }
    
    void insert(string key, int val) {
        Node* curr = root;
        for(int i = 0; i < key.length(); ++i) {
            auto next = curr->children.find(key[i]);
            if(next == curr->children.end() || next->second == nullptr) {
                Node* temp = new Node;
                curr->children[key[i]] = temp;                
                curr = temp;
            } else {
                curr = next->second;
            }
        }        
        curr->val = val;
    }
    
    int sum(string prefix) {
        Node* curr = root;        
        for(int i = 0; i < prefix.length(); ++i) {
            curr = curr->children[prefix[i]];
            if(curr == nullptr) return 0;
        }
        
        int res = 0;
        stack<Node*> st;
        st.push(curr);
        while(!st.empty()) {
            curr = st.top(); st.pop();
            res += curr->val;
            for(auto& child : curr->children) {
                if(child.second)
                    st.push(child.second);
            }
        }
        
        
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */