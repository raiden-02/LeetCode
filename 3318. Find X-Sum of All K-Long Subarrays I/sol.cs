public class Solution
{
    public int[] FindXSum(int[] nums, int k, int x)
    {
        var ret = new List<int>(Math.Max(0, nums.Length - k + 1));

        // iterate all k-length windows
        for (int i = 0; i <= nums.Length - k; i++)
        {
            // subarray [i .. i+k-1] -> end is exclusive
            int[] sliced = nums[i..(i + k)];

            // count frequencies
            var counts = new Dictionary<int, int>();
            foreach (var num in sliced)
                counts[num] = counts.GetValueOrDefault(num, 0) + 1;

            // min-heap by (count asc, key asc) so the least-frequent (and smaller key on tie)
            // is removed when size exceeds x, leaving top x by (count desc, key desc)
            var comparer = Comparer<(int value, int key)>.Create((a, b) =>
            {
                int cmp = a.value.CompareTo(b.value);
                if (cmp == 0) cmp = a.key.CompareTo(b.key);
                return cmp;
            });

            // element carries both key and count so we can compute num*count later
            var pq = new PriorityQueue<(int num, int count), (int value, int key)>(comparer);

            foreach (var kv in counts)
            {
                pq.Enqueue((kv.Key, kv.Value), (kv.Value, kv.Key));
                if (pq.Count > x) pq.Dequeue(); // drop the least frequent
            }

            int ans = 0;
            while (pq.Count > 0)
            {
                var (num, count) = pq.Dequeue();
                ans += num * count; // sum of resulting array = sum over top-x (num * frequency)
            }

            ret.Add(ans);
        }

        return ret.ToArray();
    }
}
