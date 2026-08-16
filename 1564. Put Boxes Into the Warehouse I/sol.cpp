class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int ans = 0;
        
        while(ans < warehouse.size() and not boxes.empty()) {
            if(warehouse[ans] >= boxes.back())
                ans++;
            
            boxes.pop_back();
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int ans = 0, m = boxes.size();
        
        for(int i = 0; i < m and ans < warehouse.size(); i++) {
            if(warehouse[ans] >= boxes[m - i - 1])
                ans++;
        }
        
        return ans;
    }
};
