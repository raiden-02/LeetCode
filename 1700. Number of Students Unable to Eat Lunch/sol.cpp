class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> q;
        reverse(sandwiches.begin(), sandwiches.end());
        int len = students.size(), cnt = 0;

        for(int x : students) q.push(x);
        for(int x : sandwiches) st.push(x);

        while(cnt < len && !q.empty() && !st.empty()) {
            if(st.top() == q.front()) {
                st.pop(), q.pop();
                cnt = 0;
                len = q.size();
            }

            else {
                int x = q.front();
                q.pop();
                q.push(x);
                cnt++;
            }
        }

        return q.size();
    }
};
