class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> mp;
        for(auto &x : items)
            mp[x[0]].push_back(x[1]);
        
        auto comp = [&](int &a, int &b) {
            return a > b;
        };
        
        vector<vector<int>> ans;
        for(auto &x : mp) {
            int sum = 0;
            vector<int> tmp = x.second;
            sort(tmp.begin(), tmp.end(), comp);
            
            for(int i = 0; i < 5; i++)
                sum += tmp[i];
            
            ans.push_back({x.first, sum / 5});
        }
        return ans;
    }
};
