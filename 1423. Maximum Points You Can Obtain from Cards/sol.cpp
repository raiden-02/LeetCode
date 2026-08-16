class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0, r = 0, n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(n == k)
            return total;
        
        int s = 0, ans = INT_MAX;
        
        while(r < n) {
            s += cardPoints[r];
            
            while(r - l + 1 > n - k)
                s -= cardPoints[l], l++;
            
            if(r - l + 1 == n - k)
                ans = min(ans, s);
            
            r++;
        }
        
        return total - ans;
    }
};

//concise

// --- alternate solution ---

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int n = cardPoints.size();
        vector<int> sum(n + 1);
        
        for(int i = 1; i < n + 1; i++)
            sum[i] = sum[i - 1] + cardPoints[i - 1];
        
        int ans = INT_MAX, total = sum[n];
        
        for(int i = 0; i < k + 1; i++) {
            int s = sum[i + n - k] - sum[i];
            ans = min(ans, s);
        }
        
        return total - ans;
    }
};

//intuitive sliding window

// --- alternate solution ---

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int end = n - 1, endsum = 0;
        int start = k - 1, startsum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int ans = startsum;
        
        while(start >= 0) {
            startsum -= cardPoints[start--];
            endsum += cardPoints[end--];
            ans = max(ans, startsum + endsum);
        }
        
        return ans;
    }
};
