class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26);
        int maxfreq = 0;
        for(char x : tasks) mp[x - 'A']++, maxfreq = max(maxfreq, mp[x - 'A']);
        maxfreq--;
        int gaps = maxfreq * n;
        bool f = false;

        for(int i = 0; i < 26; i++) {
            if(not f and mp[i] - 1 == maxfreq) {
                f = true;
                continue;
            }

            gaps -= min(maxfreq, mp[i]);
        }

        return max(0, gaps) + tasks.size();
    }
};
