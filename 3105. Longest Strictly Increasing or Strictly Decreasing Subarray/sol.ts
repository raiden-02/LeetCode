function longestMonotonicSubarray(nums: number[]): number {
    const n = nums.length;
    if(n <= 1) return n;
    
    let cntI = 1, cntD = 1;
    let ans = 1;

    for(let i = 0; i < n - 1; i++) {
        cntI = nums[i] < nums[i + 1] ? cntI + 1 : 1;
        cntD = nums[i] > nums[i + 1] ? cntD + 1 : 1;
        ans = Math.max(ans, Math.max(cntI, cntD));
    }

    return ans;
};
