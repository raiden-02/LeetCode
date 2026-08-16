class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<bool> vis(rooms.size());
        vis[0] = true;
        for(int &i : rooms[0])
            q.push(i);
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            vis[cur] = true;
            for(int &i : rooms[cur]) {
                if(vis[i]) continue;
                q.push(i);
            }
        }
        
        int ans = 0;
        for(bool f : vis)
            if(f) ans++;
        
        return ans == rooms.size();
    }
};

// --- alternate solution ---

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        int n = rooms.size(), cnt = 1;
        vector<bool> vis(n);
        vis[0] = true;

        while(not q.empty()) {
            int cur = q.front(); q.pop();

            for(int neigh : rooms[cur]) {
                if(vis[neigh]) continue;

                q.push(neigh), vis[neigh] = true, cnt++;
            }
        }

        return cnt == n;
    }
};
