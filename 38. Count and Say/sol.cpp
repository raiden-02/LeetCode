class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string prevSay = countAndSay(n - 1), ans;
        int cnt = 1;
        
        for(int i = 1; i < prevSay.length(); i++) {
            if(prevSay[i] == prevSay[i - 1]) {
                cnt++;
            }
            
            else {
                ans += to_string(cnt) + prevSay[i - 1];
                cnt = 1;
            }
        }
        
        ans += to_string(cnt) + prevSay.back();
        
        return ans;
    }
};
