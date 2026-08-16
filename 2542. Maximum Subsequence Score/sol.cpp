class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pnums(n);

        for(int i = 0; i < n; i++)
            pnums[i] = {nums2[i], nums1[i]};

        sort(pnums.rbegin(), pnums.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;

        for(auto &[m, s] : pnums) {
            sum += s;
            pq.push(s);

            if((int)pq.size() > k) sum -= pq.top(), pq.pop();

            if((int)pq.size() == k) ans = max(ans, sum * m);
        }

        return ans;
    } 
};
