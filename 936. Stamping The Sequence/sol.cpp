class Solution {
    vector<int> ans;
    bool flag = false;
    /*stamp = "abca", target = "aabcaca"
    aabcaca -> a????ca -> ?????ca -> ???????
    */
    void helper(string const& stamp, string &tar) {
        for(int i = 0; i < tar.length(); i++) {
            int t = i, j = 0;
            bool f = false;
            
            while(j < stamp.length() && (tar[t] == stamp[j] || tar[t] == '?')) {
                if(tar[t] == stamp[j]) f = true;
                t++, j++;
            }
            
            if(j == stamp.length() && f) {
                for(int k = 0; k < stamp.length(); k++)
                    tar[i + k] = '?';
                
                ans.push_back(i);
                return;
            }
        }
        flag = true;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        string tar(target.length(), '?');
        
        while(tar != target) {
            helper(stamp, target);
            if(flag) return {};
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
