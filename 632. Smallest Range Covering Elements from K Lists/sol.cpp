class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int> :: iterator it;
        
        auto comp = [&](auto &a, auto &b) {
            return *a.first > *b.first;  //compare the start value not the iterator pq compares in the opposive order (unless you use greater), so b is at the top
        };
        
        priority_queue<pair<it, it>, vector<pair<it, it>>, decltype(comp)> pq(comp);
        
        int start = INT_MAX, end = INT_MIN;
        
        for(auto &num : nums) {
            start = min(start, num[0]);
            end = max(end, num[0]);
            pq.push({num.begin(), num.end()});
        }
        vector<int> ans = {start, end};
        //cout << "ans: " << ans[0] << " " << ans[1] << endl;
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            //cout << *cur.first << endl;
            cur.first++;
            
            if(cur.first == cur.second)
                return ans;

            pq.push(cur);
            
            end = max(end, *cur.first);
            start = *pq.top().first;
            //cout << start << " " << end << endl;
            if(end - start < ans[1] - ans[0])
                ans = {start, end};
            //cout << "ans: " << ans[0] << " " << ans[1] << endl;
        }
        
        return ans;
    }
};
