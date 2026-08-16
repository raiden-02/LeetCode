class NumArray {
    vector<int> nums, farr;
    int n;
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        farr.resize(n + 1);
        
        for(int i = 0; i < n; i++) farr[i + 1] = farr[i] + nums[i];
        
        for(int i = n; i > 0; i--) {
            int parent = i - (i & -i); //removing the last bit that is making rightmost 1 bit to 0 leads to its parent
            
            if(parent > 0)
                farr[i] -= farr[parent];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        
        for(int i = index + 1; i < n + 1; i += (i & -i)) //the incrementor leads to its child
            farr[i] += diff;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
    
    int sum(int index) {
        int s = 0;
        
        for(int i = index; i > 0; i -= (i & -i)) //the decrementor leads to its parent
            s += farr[i];
        
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
 
 
//fenwick, binary indexed tree

// --- alternate solution ---

class NumArray {
    int n;
    vector<int> farr;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        
        if(n == 0)
            return;
        
        farr = vector<int>(n + 1);
        for(int i = 0; i < n; i++) {
            farr[i + 1] = farr[i] + nums[i];
        }
        for(int i = n; i > 0; i--) {
            int parent = i - (i & -i);
            if(parent >= 0)
                farr[i] -= farr[parent];
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        increment(index, delta);
    }
    
    void increment(int i, int val) {
        i += 1;
        while(i < n + 1) {
            farr[i] += val;
            i += (i & -i);
        }
    }
    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }
    
    int sum(int i) {
        int ans = 0;
        i += 1;
        while(i > 0) {
            ans += farr[i];
            i -= (i & -i);
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
