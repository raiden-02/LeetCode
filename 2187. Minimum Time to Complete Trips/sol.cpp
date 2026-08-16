class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = (long long)totalTrips * *max_element(time.begin(), time.end());

        while(l < r) {
            long long mid = (l + r) >> 1;
            long long trips = 0;

            for(int x : time) {
                trips += mid / x;
            }

            if(trips >= totalTrips) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
