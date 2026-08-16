class Solution {
    bool canProduce(long long budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost, int alloys) {
        for(auto &x : composition) {
            long long curcost = 0;

            for(int i = 0; i < x.size(); i++) {
                long long req = (long long)alloys * (long long)x[i] - stock[i];

                if(req > 0) curcost += cost[i] * req;
            }

            if(curcost <= budget) return true;
        }

        return false;
    }
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
       int left = 0, right = 1e9 + 7;  
        while (left < right) {
            int mid = left + (right - left + 1) / 2; 

            if (canProduce(budget, composition, stock, cost, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};
