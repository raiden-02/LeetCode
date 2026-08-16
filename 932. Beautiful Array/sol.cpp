class Solution {
    //question implies to divide the array with odds first then evens
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans = {1};
        
        while(ans.size() < N) {
            vector<int> tmp;
            
            for(int i : ans)
                if(i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
            
            for(int i : ans)
                if(i * 2 <= N) tmp.push_back(i * 2);
            
            ans = tmp;
        }
        
        return ans;
    }
};
