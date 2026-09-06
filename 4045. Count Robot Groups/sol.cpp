class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        const int n = position.size();
        vector<int> groups;

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || position[i + 1] - position[i] > distance)
                groups.push_back(speed[i]);
        }

        int speed_ahead = groups.back();
        int ans = 1; // at least one group (last group)
        
        for (int i = static_cast<int>(groups.size()) - 2; i >= 0; i--) {
            if (groups[i] <= speed_ahead) {
                speed_ahead = groups[i];
                ans++;
            }
        }

        return ans;
    }
};
