// intuitive time complexity O(m * n)

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        int ans = 0;
        
        for(auto &x : picture) {
            if(count(x.begin(), x.end(), 'B') == 1) {
                int ind = find(x.begin(), x.end(), 'B') - x.begin();
                int c = 0;
                bool f = true;
                
                for(int i = 0; i < m; i++) {
                    if(picture[i][ind] == 'B')
                        c++;
                    
                    if(c > 1) {
                        f = false;
                        break;
                    }
                }
                
                if(f)
                    ans++;
            }
        }
        
        return ans;
    }
};
