class Solution {
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i = 0; i < 26; i++) parent[i] = i;
        
        for(string &x : equations) {
            int a = x[0] - 'a';
            int b = x.back() - 'a';
            
            if(x[1] == '=')
                parent[find(a)] = find(b);
        }
        
        for(string &x : equations) {
            int a = x[0] - 'a';
            int b = x.back() - 'a';
            
            if(x[1] == '!' and find(a) == find(b))
                return false;
        }
        
        return true;
    }
};
