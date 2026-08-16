class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        size_t m = target.size();
        vector<int> arr(m);
        vector<string> ans;
        int ind = 0, cur = 1;
        
        while(ind < m && cur <= n) {
            if(arr[ind] != target[ind]) {
                if(arr[ind] == 0) {
                    arr[ind] = cur++;
                    ans.push_back("Push");
                }

                else {
                    arr[ind] = 0;
                    ans.push_back("Pop");
                }
            }

            else {
                ++ind;
            }
        }

        return ans;
    }
};
