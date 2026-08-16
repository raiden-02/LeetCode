class Solution {
public:
    int getSum(int a, int b) {
        while(b) /*until there is no carry*/ {
            int carry = uint32_t(a & b) << 1; //carry applied one pos to the left , & gives carry if both are 1s there is a carry of 1
            a = a ^ b; //xor to simulate addition one's position without carry
            b = carry;
        }
        
        return a;
    }
};
