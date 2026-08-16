class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> g;
        
        for(int i = 0; i < arr.size(); i++)
            g[arr[i]].push_back(i);
        
        vector<bool> vis(arr.size());
        queue<int> q;
        q.push(0);
        int ans = 0;
        
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int cur = q.front(); q.pop();
                if(cur == arr.size() - 1)
                    return ans;
                vis[cur] = true;
                
                if(cur - 1 >= 0 && !vis[cur - 1])
                    q.push(cur - 1);
                
                if(cur + 1 < arr.size() && !vis[cur + 1])
                    q.push(cur + 1);
            
                for(int &neigh : g[arr[cur]]) {
                    if(vis[neigh]) continue;
                    q.push(neigh);
                }
                g.erase(arr[cur]);
            }
            ans += 1;
        }
        
        return ans;
    }
};
