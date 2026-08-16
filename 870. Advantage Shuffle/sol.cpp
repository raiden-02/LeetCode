/* initial solutuion
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int c = 0;
        vector<int> index;
        vector<int> tmp = B;
        
        while(c < B.size()) {
            int m = max_element(tmp.begin(), tmp.end()) - tmp.begin();
            index.push_back(m);
            tmp[m] = -1;
            c += 1;
        }
        
        priority_queue<int> pq(A.begin(), A.end());
        vector<int> ans(A.size(), -1);
        
        for(int i : index) {
            if(pq.top() > B[i]) {
                ans[i] = pq.top();
                pq.pop();
            }
        }
        
        if(!pq.empty()) {
            for(int i = 0; i < ans.size(); i++) {
                if(ans[i] == -1) {
                    ans[i] = pq.top();
                    pq.pop();
                }
                if(pq.empty())
                    break;
            }
        }
        
        return ans;
    }
};
*/
//optimised solution

// --- alternate solution ---

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> st(A.begin(), A.end());
        
        for(int i = 0; i < B.size(); i++) {
            auto least_greater_val = st.upper_bound(B[i]);
            
            if(least_greater_val == st.end())
                least_greater_val = st.begin(); //least val
            
            A[i] = *least_greater_val;
            st.erase(least_greater_val);
        }
        
        return A; 
    }
};
