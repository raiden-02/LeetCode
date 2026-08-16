class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto &x : nums) mp[x]++;
        
        int maxf = 0;
        unordered_map<int, vector<int>> freq;
        for(auto &x : mp) freq[x.second].push_back(x.first), maxf = max(maxf, x.second);
        
        vector<vector<int>> bucket(maxf + 1);
        for(auto &x : freq) bucket[x.first] = x.second;
        
        int i = maxf;
        vector<int> ans;
        
        while(k and i >= 0) {
            for(int j = 0; j < bucket[i].size(); j++, k--)
                ans.push_back(bucket[i][j]);
            i--;
        }
        
        return ans;
    }
};

// --- alternate solution ---

//O(nlogk) intuitive
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto &x : nums) mp[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &x : mp) {
            pq.push({x.second, x.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        
        while(not pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};

//O(n) bucket sort
