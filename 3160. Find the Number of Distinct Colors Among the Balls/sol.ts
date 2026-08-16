function queryResults(limit: number, queries: number[][]): number[] {
    const colorMap: Map<number, number> = new Map();
    const colorFreq: Map<number, number> = new Map();
    const ans: number[] = []

    queries.forEach((query, _) => {
        const existingColor: number = colorMap.has(query[0]) ? colorMap.get(query[0]) : -1;

        colorMap.set(query[0], query[1])

        if(colorFreq.has(existingColor)) {
            colorFreq.set(existingColor, colorFreq.get(existingColor) - 1);
            if(colorFreq.get(existingColor) <= 0)
                colorFreq.delete(existingColor);
        }

        const getOrDefault = colorFreq.has(query[1]) ? colorFreq.get(query[1]) : 0;
        colorFreq.set(query[1], getOrDefault + 1);

        ans.push(colorFreq.size);
    })

    return ans;
};
