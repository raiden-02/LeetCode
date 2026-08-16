function minimumRecolors(blocks: string, k: number): number {
    const mp: Map<string, number> = new Map();
    let l: number = 0, ans: number = Infinity;

    for (let r: number = 0; r < blocks.length; r++) {
        mp.set(blocks[r], (mp.get(blocks[r]) || 0) + 1);

        if (r - l + 1 === k) {
            ans = Math.min(ans, mp.get('W') || 0);
            mp.set(blocks[l], mp.get(blocks[l])! - 1);
            l += 1;
        }
    }

    return ans;
}
