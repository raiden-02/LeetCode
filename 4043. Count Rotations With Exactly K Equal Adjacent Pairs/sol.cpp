class Solution {
public:
    int countRotations(string s, int k) {
        // aabaab
        const size_t n = s.size();
        s += s;
        int ans = 0;
        
        for (size_t i = 0; i < n; i++) {
            string_view view = string_view{s}.substr(i, n);
            int score = 0;
            
            for (size_t j = 0; j < n - 1; j++) {
                if (view[j] == view[j + 1]) score++;
            }

            if (score == k) ans++;
        }

        return ans;
    }
};
