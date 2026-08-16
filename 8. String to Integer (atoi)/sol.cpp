class Solution {
public:
    int myAtoi(string s) {
        if(s.empty())
            return 0;
        
        int i = 0;
        bool f = true;
        while(s[i] == ' ')
            i += 1;
        
        if(s[i] == '-') {
            f = false;
            i++;
        } else if(s[i] == '+') i++;
        
        s = s.substr(i);
        long ans = 0;
        
        for(char x : s) {
            if(!(x >= '0' && x <= '9'))
                return ans;
            
            if(!f)
                ans = 10*ans - (x - '0');
            else
                ans = 10*ans + (x - '0');
            
            if(ans < INT_MIN)
                return INT_MIN;
            if(ans > INT_MAX)
                return INT_MAX;
        }
        return ans;
    }
};
