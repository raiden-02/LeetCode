class Solution {
    struct TrieNode {
        vector<TrieNode*> children = vector<TrieNode*>(26);
        string word;
    };
    
    int m, n;
    vector<string> ans;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool bound(int i, int j) {
        return i >= 0 and i < m and j >= 0 and j < n;
    }
    
    TrieNode* build(vector<string> &words) {
        TrieNode* root = new TrieNode();
        
        for(string &x : words) {
            TrieNode *cur = root;
            
            for(char c : x) {
                if(not cur->children[c - 'a'])
                    cur->children[c - 'a'] = new TrieNode();
                
                cur = cur->children[c - 'a'];
            }
            
            cur->word = x;
        }
        
        return root;
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        
        if(c == '*' or not node->children[c - 'a']) return;
        
        node = node->children[c - 'a'];
        
        if(not node->word.empty())
            ans.push_back(node->word), node->word = "";
        
        board[i][j] = '*';
        
        for(auto &dir : dirs) {
            int di = i + dir.first, dj = j + dir.second;
            
            if(bound(di, dj)) dfs(board, di, dj, node);
        }
        
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        TrieNode* root = build(words);
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dfs(board, i, j, root);
        
        return ans;
    }
};

212. Word Search II

// --- alternate solution ---

class Solution {
    struct Node {
        vector<Node*> children;
        string word;
        
        Node() {
            children = vector<Node*>(26, nullptr);
        }
    };
    
    vector<string> ans;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    Node* root;
    
    void insert(string const& word) {
        Node* cur = root;

        for(char x : word) {
            if(not cur->children[x - 'a'])
                cur->children[x - 'a'] = new Node();
            cur = cur->children[x - 'a'];
        }

        cur->word = word;
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, Node* node) {
         char c = board[i][j];
        
        if(c == '*' or not node->children[c - 'a']) return;
        
        node = node->children[c - 'a'];
        
        if(not node->word.empty())
            ans.push_back(node->word), node->word = "";
        
        board[i][j] = '*';
        
        for(auto &dir : dirs) {
            int di = i + dir.first, dj = j + dir.second;
            
            if(di >= 0 and di < board.size() and dj >= 0 and dj < board[0].size()) dfs(board, di, dj, node);
        }
        
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        
        for(string &word : words)
            insert(word);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size();  j++)
                dfs(board, i, j, root);
        }
        
        return ans;
    }
};
