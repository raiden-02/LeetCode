class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = text.length(), c = 0;
        unordered_map<int, int> mp2;
        
        for(char x : text) mp2[x]++;
        
        for(auto &x : mp2) {
            if(x.first == 'b' or x.first == 'a' or x.first == 'n')
                ans = min(ans, x.second), c++;
            
            else if(x.first == 'l' or x.first == 'o')
                ans = min(ans, x.second / 2), c++;
        }
        
        return c != 5 ? 0 : ans;
    }
};
