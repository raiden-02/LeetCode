class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int prev = 0, maxm = 0;
        vector<int> times(26);
        
        for(int i = 0; i < releaseTimes.size(); i++) {
            int ind = keysPressed[i] - 'a';
            times[ind] = max(times[ind], releaseTimes[i] - prev);
            prev = releaseTimes[i];
            maxm = max(maxm, times[ind]);
        }
        
        for(int i = 25; i >= 0; i--) if(times[i] == maxm) return i + 'a';
        
        return '*';
    }
};
