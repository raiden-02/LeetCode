class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        vector<int> ans;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < ppid.size(); i++)
            mp[ppid[i]].push_back(i);
        
        ans.push_back(kill);
        queue<vector<int>> q;
        q.push(mp[kill]);
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(int &index : cur) {
                int val = pid[index];
                ans.push_back(val);
                q.push(mp[val]);
            }
        }
        return ans;
    }
};
