class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        int n = nums1.size();
        
        for(int i = 0; i < n; i++) {
            long long diff = nums1[i] - nums2[i];
            long long adiff = abs(diff);
            if(k != 0 and diff < 0 and adiff % k == 0) {
                cnt1 += adiff / k;
            }
            
            else if(k != 0 and diff > 0 and adiff % k == 0) {
                cnt2 += adiff / k;
            }
            
            else if(diff == 0)
                cnt3++;
            
            else
                cnt4++;
        }
        
        if(cnt3 == n) return 0;
        if(cnt4 == n) return -1;
        if(cnt1 == cnt2) {
            if(cnt1 != 0) return cnt1;
        }
        
        return -1;
    }
};
