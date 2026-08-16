function topKFrequent(nums: number[], k: number): number[] {
    function comparator([, frequency]: [number, number]) {
        return frequency;
    }

    const mp = new Map<number, number>();
    const pq = new MinPriorityQueue({priority: comparator});

   for(const num of nums){
        if(!mp.has(num))
            mp.set(num, 0);
        mp.set(num, mp.get(num) + 1);
   }

   const ans = [];

   for(const [elem, freq] of mp) {
       pq.enqueue([elem, freq]);
       
       while(pq.size() > k) {
           pq.dequeue();
       }
   }

   while(!pq.isEmpty()) {
       ans.push(pq.dequeue().element[0]);
   }

   return ans;

};
