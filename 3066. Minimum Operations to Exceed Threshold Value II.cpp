#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        int ans = 0;

        while(pq.size() >= 2 && pq.top() < k) {
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();

            pq.push(min(x, y) * 2 + max(x, y));
            ans += 1;
        }

        return ans;
    }
};
