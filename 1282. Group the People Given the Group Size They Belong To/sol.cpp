class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<vector<int>>> groups(n + 1);

        for(int i = 0; i < n; i++) {
            int groupSize = groupSizes[i];
            int person = i;

            if(groups[groupSize].empty() || (int)groups[groupSize].back().size() >= groupSize) {
                groups[groupSize].push_back({});
            }

            groups[groupSize].back().push_back(i);
        }

        vector<vector<int>> ans;

        for(auto &x : groups) {
            for(auto &y : x) ans.push_back(y);
        }

        return ans;
    }
};
