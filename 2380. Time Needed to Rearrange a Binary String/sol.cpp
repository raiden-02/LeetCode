class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool f = true;
        int ans = 0;
        
        while(f) {
            f = false;
            
            for(int i = 0; i < s.length() - 1;) {
                if(s[i] == '0' and s[i + 1] == '1') {
                    f = true;
                    s[i] = '1', s[i + 1] = '0';
                    i += 2;
                }
                
                else
                    i++;
            }
            
            ans++;
        }
        
        return ans - 1;
    }
};
