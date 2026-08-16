function tupleSameProduct(nums: number[]): number {
    const n = nums.length;
    const mp: Map<number, number> = new Map();

    for(let i = 0; i < n; i++) {
        for(let j = i + 1; j < n; j++) {
            const get_or_default_val = mp.get(nums[i] * nums[j]) ?? 0;
            mp.set(nums[i] * nums[j], get_or_default_val + 1);
        }
    }

    let ans: number = 0;

    for(const [key, value] of mp) {
        if(value >= 2) {
            const n_elements: number = value * 2;
            ans += n_elements * 1 * (n_elements - 2) * 1; 
        }
    }

    return ans;

};
