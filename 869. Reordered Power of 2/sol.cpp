class Solution {
    int counter(unordered_map<int, int> &frq, int num) {
        int c = 0;
         while(num) {
            int rem = num % 10;
            num /= 10;
            frq[rem]++;
            c++; 
        }
        
        return c;
    }
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> frq;
        int len = counter(frq, n);
        
        for(int i = 1; ; i *= 2) {
            unordered_map<int, int> mp;
            int c = counter(mp, i);
            
            if(c > len) return false;
            
            bool f = true;
            
            for(auto &x : frq) {
                if(x.second != mp[x.first]) {
                    f = false;
                    break;
                }
            }
            
            if(f)
                return true;
        }
        
        return false;
    }
};
