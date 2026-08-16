class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        
        for(string &x : logs) {
            if(x == "../")
                ans = ans == 0 ? 0 : ans - 1;
            
            else if(x == "./")
                continue;
            
            else
                ans++;
        }
        
        return ans;
    }
};
