class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;

        for(char x : word) {
            if(!cur->children[x])
                cur->children[x] = new Node();
            cur = cur->children[x];
        }

        cur->isWord = true;
    }

    bool helper(string const& word, Node* cur, int ind) {
        if(ind == word.length()) {
            return cur->isWord;
        }

        char x = word[ind];

        if(x == '.') {
            for(auto &[ch, node] : cur->children) {
                if(helper(word, node, ind + 1))
                    return true;
            }
        }

        else {
            if(cur->children.count(x) && helper(word, cur->children[x], ind + 1))
                return true; 
        }

        return false;
    }

    bool search(string word) {
        return helper(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// --- alternate solution ---

struct Node {
    unordered_map<char, Node*> children;
    bool isWord;
public:
    Node() {
        isWord = false;
    }
};
