class Solution {
public:
    int shortestWay(string source, string target) {
        int ti = 0, ans = 0, m = source.length(), n = target.length();
        
        while(ti < n) {
            int i = 0;
            int prev = ti;
            
            while(i < m && ti < n) {
                if(source[i] == target[ti])
                    ti++;
                i++;
            }
            
            if(ti == prev)
                return -1;
            ans++;
        }
        
        return ans;
    }
};
