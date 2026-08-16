class Solution {
public:
    int minDeletions(string s) {
        vector<int> fmap(26);
        unordered_set<int> vis;
        int ans = 0;
        
        for(char x : s) fmap[x - 'a']++;
        
        sort(fmap.rbegin(), fmap.rend());
        
        for(int i = 0; i < fmap.size(); i++) {
            if(fmap[i] == 0) break;
            
            if(i == 0)
                vis.insert(fmap[i]);
            
            else {
                int freq = fmap[i];
            
                while(freq and vis.find(freq) != vis.end())
                    freq--, ans++;;

                vis.insert(freq);
            }
        }
        
        return ans;
    }
};
