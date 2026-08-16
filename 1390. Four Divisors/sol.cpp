class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0, c, s;
        bool f;
        
        for(int &x : nums) {
            c = 0, s = 0;
            f = true;
            
            for(int i = 1; i * i <= x; i++) {
                if(x % i == 0) {
                    if(x / i == i)
                        s += i, c++;
                    else
                        s += (i + x / i), c += 2;
                }
                
                if(c > 4) {
                    f = false;
                    break;
                }
            }
            
            if(f and c == 4)
                ans += s;
        }
        
        return ans;
    }
};
