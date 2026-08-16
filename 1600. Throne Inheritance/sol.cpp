class ThroneInheritance {
    unordered_map<string, vector<string>> g;
    unordered_set<string> dead;
    string root;
public:
    ThroneInheritance(string kingName) {
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        g[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, root);
        return ans;
    }
    
    void dfs(vector<string> &ans, string cur) {
        if(dead.find(cur) == dead.end())
            ans.push_back(cur);
        
        for(string &child : g[cur])
            dfs(ans, child);
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
