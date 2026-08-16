class Solution {
public:
    string rankTeams(vector<string>& ratings) {
        int n = ratings[0].length();
        vector<vector<int>> elo(26, vector<int>(n));
    
        for(int i = 0; i < n; i++) {
            for(string &x : ratings)
                elo[x[i] - 'A'][i]++;
        }

        auto comp = [&](const char& x, const char& y) {
            return elo[x - 'A'] > elo[y - 'A'] or (elo[x - 'A'] == elo[y - 'A'] and x < y);
        };

        string ans = ratings[0];
        sort(ans.begin(), ans.end(), comp);

        return ans;
    }
};
