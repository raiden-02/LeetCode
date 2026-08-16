class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), curtime = 0;
        double ans = 0;

        for(auto const& x : customers) {
            int time = x[0];
            int preptime = x[1];

            curtime = max(curtime, time);
            curtime += preptime;

            ans += curtime - time;
        }

        return ans / (double)n;
    }
};
