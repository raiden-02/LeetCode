function applyOperations(nums: number[]): number[] {
    for(let i = 0; i < nums.length - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    const ans: number[] = new Array(nums.length).fill(0);
    let ind = 0;

    for(const x of nums) {
        if(x != 0) ans[ind++] = x;
    }

    return ans;
};
