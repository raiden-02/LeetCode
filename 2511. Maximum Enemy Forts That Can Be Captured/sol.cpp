class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0, n = forts.size();
        int prev = -1, cnt = -1;
        
        for(int i = 0; i < n; i++) {
            if(forts[i] != 0) {
                if(cnt >= 0 and forts[i] == -1 and forts[prev] == 1)
                    ans = max(ans, cnt), cnt = 0;
                
                if(forts[i] == 1) cnt = 0;
                
                prev = i;
            }
            
            else if(cnt >= 0)
                cnt++;
        }
        
        cnt = -1;
        
        for(int i = n - 1; i >= 0; i--) {
            if(forts[i] != 0) {
                if(cnt >= 0 and forts[i] == -1 and forts[prev] == 1)
                    ans = max(ans, cnt), cnt = 0;
                
                if(forts[i] == 1) cnt = 0;
                
                prev = i;
            }
            
            else if(cnt >= 0)
                cnt++;
        }
        
        return ans;
    }
};
