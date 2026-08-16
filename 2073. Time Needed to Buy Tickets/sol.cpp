class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), ans = 0;
        
        for(int i = 0; tickets[k] > 0; ) {
            if(tickets[i] > 0) {
                tickets[i]--;
                i = (i + 1) % n;
                ans++;
            }

            else {
                i = (i + 1) % n;
            }
        }

        return ans;
    }
};

// --- alternate solution ---

// O(n)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), ans = 0;
        
        for(int i = 0; i < n; i++) {
            i <= k ? ans += min(tickets[i], tickets[k]) : ans += min(tickets[i], tickets[k] - 1); // one round has passed for i > k
        }

        return ans;
    }
};

// Simulation O(m * n)
