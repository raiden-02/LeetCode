class Solution {
    vector<map<vector<int>, int>> dp;
    
    int helper(vector<string> &arr, int ind, vector<int> &freq) {
        if(ind >= arr.size()) return 0;
        
        if(dp[ind].find(freq) != dp[ind].end())
            return dp[ind][freq];
        
        int ans = 0;
        
        vector<int> tmp;
        
        for(int i = ind; i < arr.size(); i++) {
            bool f = true;
            tmp = freq;
            
            for(char x : arr[i]) {
                tmp[x - 'a']++;
                
                if(tmp[x - 'a'] > 1) {
                    f = false;
                    break;
                }
            }
            
            if(f)
                ans = max(ans, (int)(arr[i].size() + helper(arr, i + 1, tmp)));
        }
        
        return dp[ind][freq] = ans;
    }
public:
    int maxLength(vector<string>& arr) {
        dp.resize(arr.size());
        vector<int> freq(26);
        return helper(arr, 0, freq);
    }
};

// --- alternate solution ---

class Solution {
    int helper(vector<string> const& arr, vector<int> &cnt, int ind) {
        if(ind >= arr.size())
            return 0;
        
        int ans = helper(arr, cnt, ind + 1);
        string word = arr[ind];
        bool f = true;
        
        for(int i = 0; i < word.length(); i++) {
            cnt[word[i] - 'a']++;
            
            if(cnt[word[i] - 'a'] > 1)
                f = false;
        }
        
        if(f) {
            ans = max(ans, (int)word.length() + helper(arr, cnt, ind + 1));
        }
        
        for(int i = 0; i < word.length(); i++) {
            cnt[word[i] - 'a']--;
        }
        
        return ans;
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int> cnt(26);
        return helper(arr, cnt, 0);
    }
};
