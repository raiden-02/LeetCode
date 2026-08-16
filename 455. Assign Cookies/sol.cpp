class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int gi = 0, si = 0, ans = 0;

        while(gi < g.size() && si < s.size()) {
            if(s[si] < g[gi]) si++;
            else ans++, gi++, si++;
        }

        return ans;
    }
};
