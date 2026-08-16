class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, queue<int>> mp;
        int n = nums.size();

        for(int x : nums) {
            mp[x].push(x);
        }

        vector<vector<int>> ans;

        while(n) {
            vector<int> tmp;
            for(auto &x : mp) {
                if(x.second.empty()) continue;
                tmp.push_back(x.second.front());
                x.second.pop();
                n--;
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};
