class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> heightpq = {0};
        int n = buildings.size();
        vector<pair<int, int>> pointheights(2 * n);

        for(int i = 0; i < n; i++) {
            pointheights[2 * i] = {buildings[i][0], -buildings[i][2]};
            pointheights[2 * i + 1] = {buildings[i][1], buildings[i][2]};
        }

        sort(pointheights.begin(), pointheights.end());
        int curheight = 0;

        for(int i = 0; i < 2 * n; i++) {
            int point = pointheights[i].first;
            int height = pointheights[i].second;

            if(height >= 0) 
                heightpq.erase(heightpq.find(height));
            else
                heightpq.insert(-height);

            int maxheightvis = *heightpq.rbegin();
            
            if(curheight != maxheightvis) {
                curheight = maxheightvis;
                ans.push_back({point, curheight});
            }
        }

        return ans;
    }
};
