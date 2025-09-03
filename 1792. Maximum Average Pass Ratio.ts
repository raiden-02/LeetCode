function maxAverageRatio(classes: number[][], extra_students: number): number {
    const n = classes.length;
    let pq = new PriorityQueue<[number, number]>((a, b) => b[0] - a[0]);
    let ans = 0;

    for(let i = 0; i < n; i++) {
        const cur_avg = classes[i][0] / classes[i][1];
        const new_avg = (classes[i][0] + 1) / (classes[i][1] + 1);
        const diff = new_avg - cur_avg;
        pq.enqueue([diff, i]);
    }

    while(extra_students--) {
        const [max_gain, cur_index] = pq.dequeue() as [number, number];
        classes[cur_index][0]++;
        classes[cur_index][1]++;

        const cur_avg = classes[cur_index][0] / classes[cur_index][1];
        const new_avg = (classes[cur_index][0] + 1) / (classes[cur_index][1] + 1);
        const diff = new_avg - cur_avg;

        pq.enqueue([diff, cur_index]);
    }

    for(const x of classes) {
        ans += x[0] / x[1];
    }

    return ans / n;
};
