class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, ans = 0;
        while(l <= r) {
            if(people[l] + people[r] > limit)
                r -= 1;
            else {
                r -= 1;
                l += 1;
            }
            ans += 1;
        }
        return ans;
    }
};
