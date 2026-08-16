class Trie {
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        
        for(char x : word) {
            if(not cur->children[x - 'a'])
                cur->children[x - 'a'] = new Node();
            cur = cur->children[x - 'a'];
        }
        
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = root;
        
        for(char x : word) {
            if(cur->children[x - 'a'])
                cur = cur->children[x - 'a'];
            else return false;
        }
        
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = root;
            
        for(char x : prefix) {
            if(cur->children[x - 'a'])
                cur = cur->children[x - 'a'];
            else return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// --- alternate solution ---

struct Node {
    vector<Node*> children;
    Node() {
        children = vector<Node*>(26, nullptr);
    }
    bool isWord = false;
};
