class Solution {
    vector<bool> vis;
    string ans;
    unordered_map<int, vector<int>> mp;
    vector<int> ind;
    
    void helper(int node, string &s) {
        vis[node] = true;
        ans.push_back(s[node]);
        ind.push_back(node);
        
        for(int x : mp[node]) {
            if(vis[x]) continue;
    
            helper(x, s);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto &p : pairs)
            mp[p[0]].push_back(p[1]), mp[p[1]].push_back(p[0]);
        
        vis.resize(s.length());
        
        for(auto &x : mp) {
            if(vis[x.first]) continue;
            
            ans = "";
            ind.clear();
            helper(x.first, s);
            
            sort(ans.begin(), ans.end());
            sort(ind.begin(), ind.end());
            
            for(int i = 0; i < ind.size(); i++)
                s[ind[i]] = ans[i];
            
        }
        
        return s;
    }
};
