class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        int ans = 0;

        for(int x : tasks)
            freq[x]++;

        for(auto &[key, val] : freq) {
            if(val < 2) return -1;
            ans += ceil((float)val / 3);
        }

        return ans;
    }
};
