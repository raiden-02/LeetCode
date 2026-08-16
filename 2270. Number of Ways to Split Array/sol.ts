function waysToSplitArray(nums: number[]): number {
    const n: number = nums.length
    let left: number[] = new Array(n + 1).fill(0)
    let right: number[] = new Array(n + 1).fill(0)
    let ans: number = 0
    
    for(let i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
        left[i + 1] = nums[i] + left[i]
        right[j] = nums[j] + right[j + 1] 
    }

    for(let i = 1; i < n; i++) {
        ans += (left[i] >= right[i]) ? 1 : 0
    }

    return ans
};
