function maxScore(s: string): number {
    const n: number = s.length;
    let ans: number = 0;

    for(let i: number = 0; i < n - 1; i++) {
        let zeros: number = 0;
        let ones: number = 0;

        for(let j: number = 0; j < i + 1; j++) {
            if(s[j] == '0') zeros++;
        }

        for(let k: number = i + 1; k < n; k++) {
            if(s[k] == '1') ones++;
        }

        ans = Math.max(ans, zeros + ones)
    }

    return ans
};
