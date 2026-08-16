class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> highestJumps;
        int brickSum = 0, i = 0;
        
        for(; i < heights.size() - 1; i++) {
            if(heights[i] >= heights[i + 1])
                continue;
            
            else {
                int diff = heights[i + 1] - heights[i];
                highestJumps.push(diff);
                
                if(highestJumps.size() > ladders) {
                    brickSum += highestJumps.top();
                    highestJumps.pop();
                }
            }
            
            if(brickSum > bricks)
                return i;
        }
        
        return i;
    }
};

// --- alternate solution ---

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int total = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < heights.size() - 1; i++) {
            int d = heights[i + 1] - heights[i];
            
            if(d <= 0) continue;
            
            pq.push(d);
            total += d;
            
            if(total > bricks) {
                if(ladders == 0)
                    return i;
                
                else {
                    ladders -= 1;
                    total -= pq.top(); pq.pop();
                }
            }
        }
        
        return heights.size() - 1;
    }
};
