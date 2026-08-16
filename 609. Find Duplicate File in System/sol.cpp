class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        
        for(string &s : paths) {
            string dir;
            int i = 0;
            
            while(s[i] != ' ')
                dir += s[i], i++;
            
            i++;
            
            while(i < s.length()) {
                string path;
                
                while(s[i] != '(')
                    path += s[i], i++;

                i++;
                string key;

                while(s[i] != ')')
                    key += s[i], i++;
                
                while(i < s.length() and s[i] != ' ')
                    i++;
                i++;
                
                mp[key].push_back(dir + "/" + path);
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto &x : mp)
            if(x.second.size() > 1) ans.push_back(x.second);
        
        return ans;
    }
};
