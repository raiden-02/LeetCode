class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        unordered_set<string> ans;
        queue<string> q;
        q.push(expression);
        
        while(!q.empty()) {
            string cur = q.front(); q.pop();
            
            auto f = cur.find('{');
            
            if(f == string::npos) {
                ans.insert(cur);
                continue;
            }
            
            int l = f, i = f, r;
            
            while(i < cur.length() && cur[i] != '}') {
                if(cur[i] == '{') l = i;
                i++;
            }
            r = i;
            
            string done = cur.substr(0, l);
            
            vector<string> doing;
            stringstream ss(cur.substr(l + 1, r - (l + 1)));
            string k;
            while(getline(ss, k, ',')) doing.push_back(k);
            
            string tobedone = cur.substr(r + 1);
            
            for(string &x : doing) q.push(done + x + tobedone);
        }
        
        vector<string> ret;
        ret.insert(ret.end(), ans.begin(), ans.end());
        sort(ret.begin(), ret.end());

        return ret;
    }
};
