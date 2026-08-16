class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());
        
        int ans = 0;
        int m = processorTime.size(), n = tasks.size();
        int ind  = 0;
        
        for(int i = 0; i < n && ind < m; i += 4) {
            int s = 0;
            for(int j = i; j < i + 4; j++) {
                s = max(s, processorTime[ind] + tasks[j]);
            }
            
            ind++;
            
            ans = max(ans, s);
        }
        
        return ans;
    }
};
