class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int s = queries.size();
        vector<int> ans(s, -1);
        
        for(int i = 0; i < s; i++)
            queries[i].push_back(i);
        
        auto comp = [&](auto &a, auto &b) {
            return a[1] > b[1];
        };
        
        sort(rooms.begin(), rooms.end(), comp);
        sort(queries.begin(), queries.end(), comp);
        
        set<int> st;
        int j = 0;
        
        for(int i = 0; i < s; i++) {
            while(j < rooms.size() and rooms[j][1] >= queries[i][1]) {
                st.insert(rooms[j][0]);
                j++;
            }
            
            if(st.empty()) continue;
            
            int q = queries[i][0];
            auto it = st.lower_bound(q);
            
            int ans2 = it == st.end() ? -1e9 : *it;
            int ans1 = it == st.begin() ? -1e9 : *(prev(it));
            
            ans[queries[i][2]] = abs(ans2 - q) < abs(ans1 - q) ? ans2 : ans1;
        }
        
        return ans;
    }
};
