class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int maxm = neededTime[0], ans = 0, tot = neededTime[0];
        bool f = false;

        for(int i = 1; i < colors.size(); i++) {
            while(i < colors.size() && colors[i - 1] == colors[i]) {
                f = true;
                maxm = max(maxm, neededTime[i]);
                tot += neededTime[i];
                i += 1;
            }

            if(f) {
                ans += tot - maxm;
                f = false;
            }

            tot = maxm = neededTime[i];
        }

        return ans;
    }
};
