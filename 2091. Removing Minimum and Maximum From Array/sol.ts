function minimumDeletions(nums: number[]): number {
    const n: number = nums.length;
    const minIdx = nums.reduce((minI, val, i, a) => (val < a[minI] ? i : minI), 0);
    const maxIdx = nums.reduce((maxI, val, i, a) => (val > a[maxI] ? i : maxI), 0);
    const li = Math.min(minIdx, maxIdx);
    const ri = Math.max(minIdx, maxIdx);

    return Math.min(ri + 1, n - li, li + 1 + n - ri);
};
