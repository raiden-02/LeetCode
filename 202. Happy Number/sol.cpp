class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        
        int num = n, prev = -1;
        unordered_set<int> vis;
        vis.insert(num);
        
        while(1) {
            int cur = 0;
            
            while(num) {
                int d = num % 10;
                cur += (d * d);
                num /= 10;
            }
            
            prev = cur;
            num = cur;
            
            if(vis.count(cur)) break;

            vis.insert(cur);
        }
        
        return num == 1;
    }
};
