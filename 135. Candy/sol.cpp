class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ret = 0;
        vector<int> ans(n, 1);
        
        vector<pair<int, int>> tmp(n);
        
        for(int i = 0; i < n; i++)
            tmp[i] = {ratings[i], i};
        
        sort(tmp.begin(), tmp.end());
        
        for(auto &x : tmp) {
            int ind = x.second;
            
            if(ind - 1 >= 0 and ratings[ind - 1] < ratings[ind])
                ans[ind] = max(ans[ind], ans[ind - 1] + 1);
            
            if(ind + 1 < n and ratings[ind + 1] < ratings[ind])
                ans[ind] = max(ans[ind], ans[ind + 1] + 1);
            
            ret += ans[ind];
        }
        
        return ret;
    }
};

// --- alternate solution ---

//O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ret = 0;
        vector<int> left(n, 1), right(n, 1);
        
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        
        for(int i = n - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
        
        for(int i = 0; i < n; i++)
            ret += max(left[i], right[i]);
        
        return ret;
    }
};

//O(nlogn)
