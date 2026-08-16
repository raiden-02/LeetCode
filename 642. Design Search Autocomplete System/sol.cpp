class AutocompleteSystem {
    struct Node {
        unordered_map<char, Node*> children;
        bool isWord;
        int times;
        Node() {
            isWord = false;
            times = 0;
        }
    };

    Node* root = new Node();
    string prefix;

    void insert(string &s, int times) {
        Node* cur = root;
        for(char x : s) {
            if(not cur->children.count(x)) cur->children[x] = new Node();
            cur = cur->children[x];
        }

        cur->isWord = true;
        cur->times += times;
    }

    bool search(string &s) {
        Node* cur = root;
        for(char x : s) {
            if(not cur->children.count(x)) return false;
            cur = cur->children[x];
        }

        return cur->isWord;
    }

    void dfs(Node* cur, vector<pair<string, int>> &ret, string &s) {
        if(not cur) return;

        if(cur->isWord) ret.push_back({s, cur->times});

        for(int i = 0; i < 128; i++) {
            if(cur->children.count(i)) {
                s.push_back((char)i);
                dfs(cur->children[i], ret, s);
                s.pop_back();
            }
        }
    }

    vector<pair<string, int>> matchWords() {
        Node* cur = root;
        vector<pair<string, int>> ret;

        for(char x : prefix) {
            if(not cur->children.count(x)) return ret;
            cur = cur->children[x];
        }

        if(not cur) return ret;

        string tmp = prefix;
        dfs(cur, ret, tmp);
        return ret;
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i = 0; i < times.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            insert(prefix, 1);
            prefix.clear();
            return {};
        }

        prefix.push_back(c);
        vector<pair<string, int>> wordsArray = matchWords();

        sort(wordsArray.begin(), wordsArray.end(), [](auto &a, auto &b) {
            return a.second > b.second or (a.second == b.second and a.first < b.first);
        });

        vector<string> ans;

        for(int i = 0; i < min((int)wordsArray.size(), 3); i++) ans.push_back(wordsArray[i].first);

        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
