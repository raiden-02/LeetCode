class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length(), len = 0;
        vector<int> mps(26), mpp(26), ans;
        for(char x : p) mpp[x - 'a']++;

        for(int r = 0, l = 0; r < m; r++) {
            mps[s[r] - 'a']++;
            len++;

            while(l < r and len > n)
                mps[s[l++] - 'a']--, len--;
            
            if(len == n and mpp == mps) ans.push_back(l);

        }


        return ans;
    }
};
