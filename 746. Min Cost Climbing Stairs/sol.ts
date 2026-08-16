function minCostClimbingStairs(cost: number[]): number {
    const n: number = cost.length;

    for(let i = 2; i < n; i++) {
        cost[i] += Math.min(cost[i - 1], cost[i - 2]);
    }

    return Math.min(cost[n - 1], cost[n - 2]);
};
