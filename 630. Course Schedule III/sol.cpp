class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), [&](auto &a, auto &b){return a[1] < b[1];});
        int time = 0;
        
        for(auto &x : courses) {
            time += x[0];
            pq.push(x[0]);
            
            if(time > x[1])
                time -= pq.top(), pq.pop();
        }
        
        return pq.size();
    }
};
