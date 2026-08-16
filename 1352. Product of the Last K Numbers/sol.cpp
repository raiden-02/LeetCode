class ProductOfNumbers {
    vector<int> arr = {1};
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) arr = {1};
        
        else arr.push_back(arr.back() * num);
    }
    
    int getProduct(int k) {
        int n = arr.size();

        return k >= n ? 0 : arr.back() / arr[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
