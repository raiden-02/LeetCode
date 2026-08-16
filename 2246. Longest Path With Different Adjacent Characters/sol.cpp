class Solution {
    int ans = 1;
    vector<vector<int>> g;

    int helper(int cur, string const& s) {
        int maxm = 0, secondmaxm = 0;

        for(int neigh : g[cur]) {
            int neighmaxm = helper(neigh, s);

            if(s[cur] == s[neigh]) continue;

            if(neighmaxm > maxm) secondmaxm = maxm, maxm = neighmaxm;
            else if(neighmaxm > secondmaxm) secondmaxm = neighmaxm;
        }

        ans = max(ans, maxm + secondmaxm + 1);
        return maxm + 1; 
    }
public:
    int longestPath(vector<int>& parent, string s) {
        g.resize(parent.size());

        for(int i = 1; i < parent.size(); i++)
            g[parent[i]].push_back(i);

        helper(0, s);

        return ans;
    }
};
