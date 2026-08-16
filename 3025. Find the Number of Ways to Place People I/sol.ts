function numberOfPairs(points: number[][]): number {
    let ans = 0;

    points.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

    for(let i = 0; i < points.length - 1; i++) {
        const upper_y = points[i][1];
        let lower_y = Number.MIN_SAFE_INTEGER;

        for(let j = i + 1; j < points.length; j++) {
            const cur_y = points[j][1];
            if(cur_y <= upper_y && cur_y > lower_y) {
                ans += 1;
                lower_y = points[j][1];
            }

            if(cur_y == upper_y) break;
        }
    }

    return ans;
};
