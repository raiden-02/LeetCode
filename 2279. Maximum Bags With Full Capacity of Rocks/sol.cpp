class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size(), ans = 0;
        vector<int> cr(n);

        for(int i = 0; i < n; i++) {
            cr[i] = capacity[i] - rocks[i];
        }

        sort(begin(cr), end(cr));

        for(int i = 0; i < n and additionalRocks > 0; i++) {
            if(additionalRocks >= cr[i] and cr[i] > 0)
                additionalRocks -= cr[i], cr[i] = 0;
            
            else if(additionalRocks < cr[i]) break;

            if(cr[i] == 0) ans++;

            //cout << cr[i] << " ";
        }

        return ans;
    }
};
