class MapSum {
private:
    Node* root;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* cur = root;
        
        for(char x : key) {
            if(not cur->children[x - 'a'])
                cur->children[x - 'a'] = new Node();
            cur = cur->children[x - 'a'];
        }
        
        cur->val = val;
    }
    
    int sum(string prefix) {
        Node* tmp = root;
        
        for(char x : prefix) {
            if(not tmp->children[x - 'a']) return 0;
            tmp = tmp->children[x - 'a'];
        }
        
        int ret = 0;
        
        queue<Node*> q;
        q.push(tmp);
        
        while(not q.empty()) {
            Node* cur = q.front(); q.pop();
            ret += cur->val;
            
            for(int i = 0; i < 26; i++) {
                if(cur->children[i])
                    q.push(cur->children[i]);
            }
        }
        
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// --- alternate solution ---

struct Node {
    vector<Node*> children = vector<Node*>(26);
    int val = 0;
};
