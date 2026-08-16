function maxScore(nums1: number[], nums2: number[], k: number): number {
    const n: number = nums1.length;
    const pq = new MinPriorityQueue();
    const parr : number[][] = new Array(n);

    for(let i = 0; i < n; i++) {
        parr[i] = [nums2[i], nums1[i]];
    }

    parr.sort((a: number[], b: number[]): number => {
        if(a[0] == b[0]) return b[1] - a[1];
        return b[0] - a[0];
    });

    let sum: number = 0, ans: number = 0;

    for(const [m, s] of parr) {
        sum += s;
        pq.enqueue(s);

        if(pq.size() > k) sum -= pq.dequeue().element;

        if(pq.size() == k) ans = Math.max(ans, m * sum);
    }

    return ans;
};
