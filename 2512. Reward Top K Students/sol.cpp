class Solution {
public:
    vector<int> topStudents(vector<string>& posvec, vector<string>& negvec, vector<string>& report, vector<int>& student_id, int k) {
        int n = student_id.size();

        vector<pair<int, int>> scores(n);
        unordered_set<string> pos(posvec.begin(), posvec.end());
        unordered_set<string> neg(negvec.begin(), negvec.end());
        
        for(int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            string k;
            stringstream ss(report[i]);
            
            while(ss >> k) {
                if(pos.find(k) != pos.end()) scores[i].first += 3;
                else if(neg.find(k) != neg.end()) scores[i].first -= 1;
            }
            

            scores[i].second = student_id[i];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &x : scores) {
            pq.push({x.first, -x.second});
            
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans(k);
        int ind = k - 1;
        
        while(not pq.empty()) ans[ind--] = -pq.top().second, pq.pop();

        return ans;
    }
};
