class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> mp;
        for(char x : S)
            mp[x]++;
        
        priority_queue<pair<int, char>> pq;
        for(auto const&[k, v] : mp)
            pq.push({v, k});
        
        string ans;
        while(pq.size() > 1) {
            auto cur = pq.top(); pq.pop();
            auto nex = pq.top(); pq.pop();
            cur.first--; nex.first--;
            
            ans += cur.second;
            ans += nex.second;
            
            if(cur.first > 0)
                pq.push(cur);
            if(nex.first > 0)
                pq.push(nex);
        }
        
        if(!pq.empty()) {
            if(pq.top().first > 1)
                return "";
            ans += pq.top().second;
        }
        return ans;
    }
};
