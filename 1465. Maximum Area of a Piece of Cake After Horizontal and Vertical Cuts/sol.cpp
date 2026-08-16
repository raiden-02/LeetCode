class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long hmin = 0, vmin = 0;
        int mod = 1e9 + 7;
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long maxV = 0, maxH = 0;
        
        for(int j = 0; j < verticalCuts.size(); j++) {
            maxV = max(maxV, (verticalCuts[j] - vmin));
            vmin = verticalCuts[j];
        }
        
        for(int i = 0; i < horizontalCuts.size(); i++) {
            maxH = max(maxH, (horizontalCuts[i] - hmin));
            hmin = horizontalCuts[i];
        }
        
        return (maxV * maxH) % mod;
    }
};

// --- alternate solution ---

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mod = 1e9 + 7;
        
        horizontalCuts.insert(horizontalCuts.begin(), 0), verticalCuts.insert(verticalCuts.begin(), 0);
        horizontalCuts.push_back(h), verticalCuts.push_back(w);
        
        long maxw = 0, maxh = 0;
        
        for(int i = 1; i < horizontalCuts.size(); i++)
            maxw = max(maxw, (long)horizontalCuts[i] - horizontalCuts[i - 1]);
        
        for(int i = 1; i < verticalCuts.size(); i++)
            maxh = max(maxh, (long)verticalCuts[i] - verticalCuts[i - 1]);
        
        return (maxw * maxh) % mod;
    }
};
