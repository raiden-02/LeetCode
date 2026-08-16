class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indeg;
        unordered_map<char, vector<char>> g;
        
        for(string &x : words) for(char y : x) g[y] = vector<char>(), indeg[y] = 0;
        
        for(int i = 1; i < words.size(); i++) {
            string prev = words[i - 1], cur = words[i];
            
            if(prev.length() > cur.length() and prev.find(cur) == 0)
                return "";
            
            int len = min(prev.length(), cur.length());
            
            for(int j = 0; j < len; j++) {
                if(prev[j] != cur[j]) {
                    char out = prev[j], in = cur[j];
                    g[out].push_back(in);
                    indeg[in]++;
                    break;
                }
            }
        }
            
        queue<char> q;
        string ans;

        for(auto &x : indeg) {
            if(x.second == 0)
                q.push(x.first);
        }

        while(not q.empty()) {
            char cur = q.front(); q.pop();
            ans += cur;

            for(char neigh : g[cur]) {
                indeg[neigh]--;

                if(indeg[neigh] == 0) q.push(neigh);
            } 
        }
        
        return indeg.size() == ans.length() ? ans : "";
    }
};
