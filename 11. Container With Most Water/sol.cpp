class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0, area = 0;
        while(l < r) {
            area = min(height[l], height[r]) * (r - l);
            if(height[l] < height[r])
                l += 1;
            else
                r -= 1;
            ans = max(area, ans);
        }
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0;
        
        while(l < r) {
            ans = max(ans, min(height[r], height[l]) * (r - l));
            height[r] < height[l] ? r-- : l++;
        }
        
        return ans;
    }
};
