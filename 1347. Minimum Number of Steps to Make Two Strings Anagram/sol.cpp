class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mps, mpt;
        int ans = 0;

        for(char x : s) mps[x]++;
        for(char x : t) mpt[x]++;

        for(char x = 'a'; x <= 'z'; x++) {
            if(mpt[x] < mps[x])
                ans += mps[x] - mpt[x];
        }

        return ans;
    }
};
