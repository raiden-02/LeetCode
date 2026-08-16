class Solution {
    vector<vector<string>> out;
    unordered_map<string, unordered_set<string>> g;
    unordered_map<string, bool> vis;
    
    void dfs(string b, string const& e, vector<string> tmp) {
        if(b == e) {
            out.push_back(tmp);
            return;
        }
        
        for(string neigh : g[b]) {
            tmp.push_back(neigh);
            dfs(neigh, e, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        if(words.find(endWord) == words.end())
            return {};
        
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> vis = {{beginWord, 0}};
        
        while(not q.empty()) {
            int s = q.size();
            
            while(s--) {
                string cur = q.front(); q.pop();
                string neigh = cur;                
                
                for(int i = 0; i < neigh.length(); i++) {
                    char c = neigh[i];
                    for(char x = 'a'; x <= 'z'; x++) {
                        if(c == x)
                            continue;
                        
                        neigh[i] = x;
                        
                        if(words.find(neigh) != words.end()) {
                            if(vis.find(neigh) == vis.end()) {
                                vis[neigh] = vis[cur] + 1;
                                q.push(neigh);
                                g[cur].insert(neigh);
                            }
                            
                            else if(vis[neigh] == vis[cur] + 1)
                                g[cur].insert(neigh);
                        }
                    }
                    neigh[i] = c;
                }
            }
        }
        
        dfs(beginWord, endWord, {beginWord});
        
        return out;
    }
};
